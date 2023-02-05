#include <stdio.h>
#include <string.h>
/*	Ahmed Ibrahim
    1001820005*/
int meet_with_suspect(char *all_suspects[3], int meet[3], char name[100])
{
    char userInput[10];
    int check=1;
    for(int i = 0; i<3; i++)
    {
        if(!strcmp(all_suspects[i],name))
        {
            check=0;
            meet[i]++;
        }
    }
    if(check==0)
    {
        printf("Suspect found.  Adding meeting. \n");
    }
    else
    {
        printf("Suspect not found.\n");
    }

    printf("-Would you like to continue meeting?\n");
    fgets(userInput,10,stdin);
    strtok(userInput,"\n");

    if(!strcmp(userInput,"yes"))
    {
        return 1;
    }
    else if(!strcmp(userInput, "no"))
    {
        return 0;
    }
    while((strcmp(userInput, "no")) || (strcmp(userInput, "yes")))
    {
        printf("That is not a valid answer.\n");
        printf("-Would you like to continue meeting?\n");
        fgets(userInput,100,stdin);
        strtok(userInput,"\n");
        if(!strcmp(userInput,"yes"))
        {
            return 1;
        }
        else if(!strcmp(userInput, "no"))
        {
            return 0;
        }
    }
}

int main (int argc, char **argv)
{
    char* all_suspects[]={"Mustard", "Scarlet","Plum"};
    int meet[3]={0};  /*Number of times met for each suspect-each array index corresponds to the array index of the suspect name
    in all_suspects*/
    char name[100];
    int check=1;

    while(check)
    {
        printf("\n***Enter a suspect's name: ");
        fgets(name,100,stdin);
        strtok(name,"\n");

        if(!strcmp(name,"exit"))
        {
            check=0;
        }

        else
        {
            check=meet_with_suspect(all_suspects,meet,name);
        }
    }

    printf("Total meets for Mustard: %d\n",meet[0]);
    printf("Total meets for Scarlet: %d\n",meet[1]);
    printf("Total meets for Plum: %d\n",meet[2]);
}
