  #include<stdio.h>
  #include<stdlib.h>
  #include<stdbool.h>
  /*	Ahmed Ibrahim
			1001820005*/
  void print_out(int *num, char* f[])
  {
    printf("%d flavors:\n", *num);
    for(int i = 0; i<*num; i++)
    {
      printf("%s\n", f[i]);
    }
  }
  int	name_flavors(char *n, char* f[], int *s)
  {
    int matches = 0;
    for (int i = 0; i<*s; i++)
    {
      if(n==f[i][0])
      {
        printf("Flavor match! %s\n", f[i]);
        matches++;
      }
    }
    return matches;
  }

  int main()
  {
    char *flavors[10][20] = {"Chocolate", "Classic Vanilla", "Red Velvet",
                      "White chocolate", "Confetti", "Carrot",
                      "Lemon", "Marble", "Pecan Praline", "Cinnamon"};
      int* size = 10;
      int enter;
      printf("***Menu: ***\n");
      printf("1- Pick how many you want\n");
      printf("2- See if any match the first letter of your name\n");
      printf("3- To exit\n");
      scanf("%d", &enter);
      while(true)
          {
          if(enter==1)
          {
            int how;
            printf("How many do you want? ");
            scanf("%d", &how);
            print_out(&how, flavors);
            printf("\n\n");
          }
          else if(enter==2)
          {
            printf("Enter a name: \n");
            char name[15];
            scanf("%s", name);
            char* letter = name[0];
            name_flavors(letter, flavors, size);
            int returned = name_flavors(&letter, flavors, size);
            printf("Number of matches: %d", returned);
            printf("\n\n");
          }
          else if(enter==3)
          {
            printf("\nBye!");
            exit(0);
          }
        }
  }
