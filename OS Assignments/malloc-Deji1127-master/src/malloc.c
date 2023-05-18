#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define ALIGN4(s) (((((s)-1) >> 2) << 2) + 4)
#define BLOCK_DATA(b) ((b) + 1)
#define BLOCK_HEADER(ptr) ((struct _block *)(ptr)-1)

static int atexit_registered = 0;
static int num_mallocs = 0;
static int num_frees = 0;
static int num_reuses = 0;
static int num_grows = 0;
static int num_splits = 0;
static int num_coalesces = 0;
static int num_blocks = 0;
static int num_requested = 0;
static int max_heap = 0;

/*
 *  \brief printStatistics
 *
 *  \param none
 *
 *  Prints the heap statistics upon process exit.  Registered
 *  via atexit()
 *
 *  \return none
 */
void printStatistics(void)
{
   printf("\nheap management statistics\n");
   printf("mallocs:\t%d\n", num_mallocs);
   printf("frees:\t\t%d\n", num_frees);
   printf("reuses:\t\t%d\n", num_reuses);
   printf("grows:\t\t%d\n", num_grows);
   printf("splits:\t\t%d\n", num_splits);
   printf("coalesces:\t%d\n", num_coalesces);
   printf("blocks:\t\t%d\n", num_blocks);
   printf("requested:\t%d\n", num_requested);
   printf("max heap:\t%d\n", max_heap);
}

struct _block
{
   size_t size;         /* Size of the allocated _block of memory in bytes */
   struct _block *next; /* Pointer to the next _block of allcated memory   */
   bool free;           /* Is this _block free?                            */
   char padding[3];     /* Padding: IENTRTMzMjAgU3ByaW5nIDIwMjM            */
};

struct _block *heapList = NULL;  /* Free list to track the _blocks available */
struct _block *best_fit = NULL;  // Keep track of the best fitting block
struct _block *worst_fit = NULL; // Keep track of the worst fitting block
struct _block *next_fit = NULL;  // Keep track of the next fitting block
/*
 * \brief findFreeBlock
 *
 * \param last pointer to the linked list of free _blocks
 * \param size size of the _block needed in bytes
 *
 * \return a _block that fits the request or NULL if no free _block matches
 *
 * \TODO Implement Next Fit
 * \TODO Implement Best Fit
 * \TODO Implement Worst Fit
 */
struct _block *findFreeBlock(struct _block **last, size_t size)
{
   struct _block *curr = heapList;
#if defined FIT && FIT == 0
   /* First fit */
   // While we haven't run off the end of the linked list and
   // while the current node we point to isn't free or isn't big enough
   // then continue to iterate over the list.  This loop ends either
   // with curr pointing to NULL, meaning we've run to the end of the list
   // without finding a node or it ends pointing to a free node that has enough
   // space for the request
   while (curr && !(curr->free && curr->size >= size))
   {
      *last = curr;
      curr = curr->next;
   }
#endif

#if defined BEST && BEST == 0 // searches the entire likned list and finds a block that is free and has the smallest amnt of lefover space
   /* Best fit */
   // Iterate over the linked list of blocks and find the block that
   // best fits the size requested, i.e. the smallest block that has enough
   // space to fulfill the request. Keep track of the best fitting block so far.
   // If we find a block that is exactly the same size as the request, we can
   // break the loop since this is the best fit we can find.
   while (curr) // while not null (while there is still space)
   {
      if (curr->free && curr->size >= size &&
          (best_fit == NULL || curr->size < best_fit->size))
      {
         best_fit = curr;
         if (best_fit->size == size) // If we found a block that is exactly the same size as the request
         {                           // break the loop since this is the best fit we can find.
            break;
         }
      }
      *last = curr;
      curr = curr->next;
   }
   curr = best_fit;
#endif

#if defined WORST && WORST == 0
   // Iterate over the linked list of blocks and find the block that
   // worst fits the size requested, i.e. the largest block that has enough
   // space to fulfill the request. Keep track of the worst fitting block so far.
   // We want to use up as much of the available space as possible, so we choose
   // the largest block that can hold the requested size.
   while (curr)
   {
      if (curr->free && curr->size >= size &&
          (worst_fit == NULL || curr->size > worst_fit->size))
      {
         worst_fit = curr;
      }
      *last = curr;
      curr = curr->next;
   }
   curr = worst_fit;
#endif

// \TODO Put your Next Fit code in this #ifdef block
#if defined NEXT && NEXT == 0
   /* Next fit */
   // Iterate over the linked list of blocks starting from the last
   // block we looked at and find the next block that best fits the
   // size requested. This algorithm will start searching from the
   // block that immediately follows the block that was last allocated.
   if (next_fit == NULL)
   {
      next_fit = heapList;
   }
   curr = next_fit;
   bool idk = false;
   while (curr && !(curr->free && curr->size >= size))
   {
      *last = curr;
      curr = curr->next;
      if (!idk && curr == NULL)
      {
         curr = heapList;
         idk = true;
      }
   }
   next_fit = curr;
#endif

   return curr;
}

/*
 * \brief growheap
 *
 * Given a requested size of memory, use sbrk() to dynamically
 * increase the data segment of the calling process.  Updates
 * the free list with the newly allocated memory.
 *
 * \param last tail of the free _block list
 * \param size size in bytes to request from the OS
 *
 * \return returns the newly allocated _block of NULL if failed
 */
struct _block *growHeap(struct _block *last, size_t size)
{
   /* Request more space from OS */
   struct _block *curr = (struct _block *)sbrk(0);
   struct _block *prev = (struct _block *)sbrk(sizeof(struct _block) + size);

   assert(curr == prev);

   /* OS allocation failed */
   if (curr == (struct _block *)-1)
   {
      return NULL;
   }

   /* Update heapList if not set */
   if (heapList == NULL)
   {
      heapList = curr;
   }

   /* Attach new _block to previous _block */
   if (last)
   {
      last->next = curr;
   }

   /* Update _block metadata:
      Set the size of the new block and initialize the new block to "free".
      Set its next pointer to NULL since it's now the tail of the linked list.
   */
   curr->size = size;
   curr->next = NULL;
   curr->free = false;
   return curr;
}

/*
 * \brief malloc
 *
 * finds a free _block of heap memory for the calling process.
 * if there is no free _block that satisfies the request then grows the
 * heap and returns a new _block
 *
 * \param size size of the requested memory in bytes
 *
 * \return returns the requested memory allocation to the calling process
 * or NULL if failed
 */
void *malloc(size_t size)
{
   num_mallocs++;
   num_requested+=size;
   if (atexit_registered == 0)
   {
      atexit_registered = 1;
      atexit(printStatistics);
   }

   /* Align to multiple of 4 */
   size = ALIGN4(size);

   /* Handle 0 size */
   if (size == 0)
   {
      return NULL;
   }

   /* Look for free _block.  If a free block isn't found then we need to grow our heap. */

   struct _block *last = heapList;
   struct _block *next = findFreeBlock(&last, size);
   /*If the block found by findFreeBlock is larger than we need then:
            If the leftover space in the new block is greater than the sizeof(_block)+4 then
            split the block.
            If the leftover space in the new block is less than the sizeof(_block)+4 then
            don't split the block.
   */
   if (next && next->size >= size + sizeof(struct _block) + 4) /* If the block found by findFreeBlock is larger than we need then: */
   {
      size_t leftover_size = next->size - size - sizeof(struct _block);                          /* Calculate leftover space after the allocation */
      struct _block *new_block = (struct _block *)((char *)next + sizeof(struct _block) + size); /* Split block */
      new_block->size = leftover_size;
      new_block->free = true;
      new_block->next = next->next;

      next->size = size;
      next->free = false;
      next->next = new_block;

      num_splits++;
      num_blocks++;
   }
   if (next == NULL)/* Could not find free _block, so grow heap */
   {
      next = growHeap(last, size);
      num_grows++;
      num_blocks++;
      max_heap+=size;
   }
   else
   {
      num_reuses++; /* Don't split block */
   }
   /* Could not find free _block or grow heap, so just return NULL */
   if (next == NULL)
   {
      return NULL;
   }

   /* Mark _block as in use */
   next->free = false;

   /* Return data address associated with _block to the user */
   return BLOCK_DATA(next);
}

/*
 * \brief free
 *
 * frees the memory _block pointed to by pointer. if the _block is adjacent
 * to another _block then coalesces (combines) them
 *
 * \param ptr the heap memory to free
 *
 * \return none
 */
void free(void *ptr)
{
   if (ptr == NULL)
   {
      return;
   }

   /* Make _block as free */
   struct _block *curr = BLOCK_HEADER(ptr);
   assert(curr->free == 0);
   curr->free = true;
   num_frees++;

   struct _block *next = curr->next;
   struct _block *prev = heapList;
   while (prev->next != curr && prev != curr)
   {
      prev = prev->next;
   }
   if (next != NULL && next->free)
   {
      num_coalesces++;
      num_blocks--;
      curr->size += (int)next->size + sizeof(struct _block);
      curr->next = next->next;
   }
   if (prev != curr && prev->free)
   {
      num_coalesces++;
      num_blocks--;
      prev->size += (int)curr->size + sizeof(struct _block);
      prev->next = curr->next;
   }
   /*Coalesce free _blocks.  If the next block or previous block
            are free then combine them with this block being freed.
   */
}

void *calloc(size_t nmemb, size_t size)
{ // \TODO Implement realloc
   size_t total_size = nmemb * size;
   void *ptr = malloc(total_size);
   if (ptr == NULL)
   {
      return NULL;
   }
   memset(ptr, 0, total_size);
   return ptr;
}

void *realloc(void *ptr, size_t size)
{ // \TODO Implement realloc.
   // if (ptr == NULL)// If ptr is NULL
   // {
   //    return malloc(size);//then realloc is equivalent to malloc
   // }
   // else if (size == 0)// If size is 0,
   // {
   //    free(ptr);//then realloc is equivalent to free
   //    return NULL;
   // }
   // else
   // {
   //    // Attempt to resize the memory block
   //    void *new_ptr = malloc(size);
   //    if (new_ptr == NULL)
   //    {
   //       return NULL;// If malloc fails, return NULL
   //    }
   //    else
   //    {
   //       // Copy the data from the old block to the new block
   //       size_t old_size = malloc_usable_size(ptr);
   //       size_t copy_size = old_size < size ? old_size : size;
   //       memcpy(new_ptr, ptr, copy_size);
   //       free(ptr);// Free the old memory block
   //       return new_ptr;// Return the new memory block
   //    }
   // }
   // void *new = malloc(size);
   // memcpy(new,ptr,size);
   // free (ptr);
   // return new;
   // // return NULL
   void *new = malloc(size);
   if (new != NULL)
   {
      memcpy(new, ptr, size);
   }
   free(ptr);
   return new;
   // return NULL;
}
