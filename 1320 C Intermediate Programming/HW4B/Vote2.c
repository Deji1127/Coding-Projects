//Ahmed Ibrahim
//1001820005
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person { 
    char* first_name; 
    char* last_name; 
    int* number_order_registered; //1, 2, 3? etc as shown above 
}person;

int read_file(char *file_name);
void print_out(char* file_name, int size);

int main(int argc, char **argv)
{
    int size = 0;
    size = read_file(argv[1]);
    if(size != 0)
    {
        print_out(argv[2], size);
    }

    return 0;
}

int read_file(char *file_name)
{
    int size, line_size = 0;
    int i = 0;
    char c;
    char line[50];
    char *buff;
    
    FILE *fp = fopen(file_name, "r");
    if(fp == NULL)
    {
        printf("The file could not be read.\n");
        return 0;
    }
    
    for(c = getc(fp); c != EOF; c = getc(fp)) //figures out how many characters total and how many lines exist in the file (may or may not be necessary for the code)
    {
        if(c == '\n')
        {
            line_size = line_size + 1;
        }
        else
        {
            size = size + 1;
        }
    }
    person *array = malloc(sizeof(char) * size); //something I found online to test, still trying to figure out how dynamic memory allocation works (most likely used improperly)
    printf("This works too too\n");
    while(fgets(line, 50, fp)) //atempting to save all info from file (this part doesn't work)
    {
        person *array = realloc(array, sizeof(person) * size);
        printf("This works too\n");
        
        for(i = 0; i < line_size + 1; i++)
        {
            buff = strtok(line, ".");
            printf("This works\n");
            array[i].number_order_registered[i] = atoi(buff);
            printf("%d", array[i].number_order_registered[i]);
            buff = strtok(NULL, ". ");
            strcpy(array[i].first_name, buff);
            buff = strtok(NULL, " ");
            strcpy(array[i].last_name, buff);
        }
    }
    fclose(fp);
    return line_size;
}

void print_out(char* file_name, int size) //should be simple and similiar to prev. hw to print out the structs once they are saved properly
{
    person people[size];
    int i;
    FILE *of = fopen(file_name, "w");
    for(i = 0; i < size; i++)
    {
        printf("%s, %s...%d!\n", people[i].last_name, people[i].first_name, people->number_order_registered[i]);
        fprintf(of, "%s, %s...%d!\n", people[i].last_name, people[i].first_name, people->number_order_registered[i]);
    }
}