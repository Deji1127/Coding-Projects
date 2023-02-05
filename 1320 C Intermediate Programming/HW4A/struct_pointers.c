  /*Ahmed Ibrahim
    1001820005
    struct_pointers.c*/
  #include <stdio.h>
  #include <stdlib.h>

  typedef struct all_values{
    char word[40];
    float numbers[1][2];
    int** int_dblptr;
    int* int_ptr;
  }RANDOM;

  void fill_in_struct_info(RANDOM* random_stuff, int** number, int* num)
  {
      printf("Enter a word to put in random.word: ");
      scanf("%s", random_stuff->word);
      for(int i=0; i<2; i++)
      {
         printf("Enter a float for random.numbers[0][%d]: ", i);
         scanf("%f", &random_stuff->numbers[0][i]);
      }
      printf("Assigning parameter val_one to random.int_dblptr...\n");
      printf("Assigning parameter val_two to random.int_ptr...\n");
      random_stuff->int_dblptr = number;
      //printf("%d", **random_stuff->int_dblptr);
      random_stuff->int_ptr = num;
      //printf("%d", *random_stuff->int_ptr);
  }

  void print_out_struct_info(RANDOM* random_stuff)
  {
      printf("In random.word: %s\n", random_stuff->word);
      for(int i=0; i<2; i++)
      {
          printf("In random.numbers[0][%d]: %.2f\n", i, random_stuff->numbers[0][i]);
      }
      printf("Value held at random.int_dblptr: %p, acutal value: %d\n", random_stuff->int_dblptr, **random_stuff->int_dblptr);
      printf("Value held at random.int_ptr: %p, acutal value: %d\n", random_stuff->int_ptr, *random_stuff->int_ptr);
  }

  int main(int argc, char**argv)
  {
     int num=atoi(argv[1]);
     int* number=&num;

     int num_two=atoi(argv[2]);
     int* number_two=&num_two;

     RANDOM random_stuff[2];
     RANDOM* random_ptr=random_stuff;

     fill_in_struct_info(random_stuff, &number, &num); //fills in first struct element of random_stuff (random_stuff[0])
     random_ptr++;
     fill_in_struct_info(random_ptr, &number_two, &num_two); //fills in second struct element of random_stuff (random_stuff[1])

     print_out_struct_info(&random_stuff[0]); //prints out first struct element of random_stuff, at index 0
     print_out_struct_info(random_ptr); //prints out second struct element of random_stuff, at index 1
  }
