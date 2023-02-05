  #include <stdio.h>
  #include <string.h>
  #include<stdlib.h>/*	Ahmed Ibrahim
												1001820005*/
  int find_filename(int n, char **b)
  {
    int i;
    int looker=0;
    int check=0;

    for(i=0;i<n&&!check;i++)
    {
      if(!strcmp(*b, "filename"))
      {
        check=1;
      }
      looker++;
      b++;
    }
    if(check!=1)
    {
      looker=0;
    }
    return (looker-1);
  }

  int read_file(int argc, char** argv, char w[][100], int num[], int finder)
  {
      int i=0;
      int size=0;
      char words[100];
      int numbers[100];

      for(i; i<argc; i++)
      {
          if(!strcmp(*argv, "filename"))
          {
              printf("Filename: %s\n", *(argv+1));
              break;
          }
      argv++;
      }
      if(finder==1)

      {
          FILE *fp = fopen(*(argv+1), "r");
          printf("We're dealing with number info.\n\n");
          printf("Contents of the file:\n");
          while(!feof(fp))
          {
              fscanf(fp, "%d", &numbers[size]);
              num[size]=numbers[size];
              printf("%d\n", num[size]);
              size++;
          }
          fclose(fp);
          return size;
      }
      else if(finder==2)
      {
          FILE *fp = fopen(*(argv+1), "r");
          printf("We're dealing with string info.\n");
          while(!feof(fp))
          {
              fscanf(fp, "%[^\n]\n", &w[size][100]);
              printf("%s\n", &w[size][100]);
              i++;
          }
          fclose(fp);
          return size;
      }
  }
  int main(int argc, char **argv)
  {
      char words[100][100];
      int numbers[100];
      int finder;

      if(find_filename(argc, argv) == -1)
      {
          printf("No filename given. Bye!\n");
      }
      else
      {
          for(int i=0; i<argc; i++)
          {
              if(!strcmp(argv[i],"numbers"))
              {
                  finder = 1;
              }
              else if(!strcmp(argv[i],"string"))
              {
                  finder = 2;
              }
          }
          int size = read_file(argc, argv, words, numbers, finder);
      }
  }
