#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node 
{ 
   char *singer_name; 
    int *albums_sold; 
    int number_tour_cities; 
    char** tour_cities_name; 
    struct node *left; 
    struct node *right; 
 
}Node; 

void addNodeToTree(char* filename, Node **currentNode, char* singer_name, int* albums_sold, int number_tour_cities, char** tour_cities_name)
{
    FILE* fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("File did not open correctly\n");
    }
    else
    {
        char* line;
        while(fgets(line, 50, fp))
        {
            
            int i = 0;
            if(*currentNode == NULL)
            {
               *currentNode = malloc(sizeof(Node));
               strcpy((*currentNode)->singer_name, singer_name);
               *(*currentNode)->albums_sold = *albums_sold;
               (*currentNode)->number_tour_cities = number_tour_cities;
               strcpy(*(*currentNode)->tour_cities_name, *tour_cities_name);
               (*currentNode)->left = (*currentNode)->right = NULL;
            }
            else if(*albums_sold < *(*currentNode)->albums_sold)
            {
               addNodeToTree(filename, &(*currentNode)->left, singer_name, albums_sold, number_tour_cities, tour_cities_name);
            }
            else if(*albums_sold > *(*currentNode)->albums_sold)
            {
               addNodeToTree(filename, &(*currentNode)->right, singer_name, albums_sold, number_tour_cities, tour_cities_name);
            }
            else
            {
                printf("Error... node number you wanted to add already exists\n"
                "For simplicity's sake, please refrain from adding duplicate numbers\n");
            }
        }
    }
}

void freeTheTree(Node **currentNode)
{
   if((*currentNode) != NULL)
   {
      freeTheTree(&(*currentNode)->left);
      freeTheTree(&(*currentNode)->right);
      free(*currentNode);
      *currentNode = NULL;
   }
}

void removeNode(Node **currentNode, int nodeNumber)
{
   if(*currentNode == NULL)
   {
      printf("Unable to remove desired node...\n\n");
   }
   else if(*(*currentNode)->albums_sold == *albums_sold)
   {
      freeTheTree(currentNode);
   }
   else if(*albums_sold < *(*currentNode)->albums_sold)
   {
      removeNode(&(*currentNode)->left, *albums_sold);
   }
   else
   {
      removeNode(&(*currentNode)->right, *albums_sold);
   }
}

void printInOrder(Node *currentNode)
{
   if(currentNode != NULL)
   {
      printInOrder(currentNode->left);
      printf("Node number :: %d\n", currentNode->nodeNumber);
      printInOrder(currentNode->right);
   }
}

int main(int argc, char** argv)
{
   int userInput  = 0;
    int* albums_sold;
   int nodeNumber = *albums_sold;
   char* singer_name;
   int number_tour_cities;
   char** tour_cities_name;
   
   Node *root = NULL;

   // Function pointer array!
   void (*PrintTheTree[])(Node *) = {printInOrder};

   do
   {
      printf("1. Add a node to the Tree\n"
             "2. Delete a node on the Tree\n"
             "3. Print the Tree\n"
             "4. Clear the Tree\n"
             "5. Quit\n"
             "What do you want to do?\n");
      scanf("%d", &userInput);
      getchar(); // Is here to prevent non-numeric characters from breaking the program

      switch(userInput)
      {
         case 1:
            printf("What is the new node's number? ");
            scanf("%d", &nodeNumber);
            getchar();

            addNodeToTree(argv[1], &root, singer_name, albums_sold, number_tour_cities, tour_cities_name);
            break;
         case 2:
            printf("DISCLAIMER :: You can delete multiple nodes this way "
                   "be cautious with what node you want to delete\n"
                   "Which node do you want to remove? ");
            scanf("%d", &nodeNumber);
            getchar();
            removeNode(&root, nodeNumber);
            userInput = 0;
            break;
         case 3:
            if(root != NULL)
            {
                printf("\nHow do you want to print the tree?\n");
               
                printf("Printing the tree...\n");
                (*PrintTheTree[userInput-1])(root);
            }
            else
            {
               printf("The tree is empty, unable to print anything\n");
            }
            userInput = 0; // To prevent from accidentally leaving the loop
            break;
         case 4:
            printf("Clearing the tree\n");
            freeTheTree(&root);
            break;
         case 5:
            break;
         default:
            printf("Please pick an option from the menu\n");
      }
      printf("\n");
   }
   while(userInput != 5);

   freeTheTree(&root);

   return 0;
}
