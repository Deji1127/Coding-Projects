//Ahmed Ibrahim
//1001820005
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vote{
    char names[10][25];
    int counter;
}vote;

int registered(FILE *fp)
{
    vote store;
    int ask=0;
    char response;
    char* input;

    printf("***Registered so far:***\n");
    for (int i=0; i<store.counter; i++)
    {
        printf("%s\n", store.names[i]);
    }

    printf("How many people to ask right now?\n");
    scanf("%d", &ask);
    for(int i=0; i<ask; i++)
    {
        printf("Person %d:Would you like to register to vote?\n", i);
        scanf("%c", &response);
        if(response=='y')
        {
            printf("Enter name:");
            scanf("%s", input);
            printf("Adding: %s", input);
            store.counter++;
        }
        else if (response=='n')
        {
            printf("Ok.\n\n");
        }
    }

}

void new_register(FILE *fp)
{
    vote store;
    for(int i=0; i<store.counter; i++)
    {
        fprintf(fp, "%s\n", store.names[i]);
    }
}

int main(int argc, char **argv)
{
    vote store;
    FILE* fp= fopen(argv[1], "w");
    while(store.counter!=10)
    {
        store.counter=registered(fp);
    }
    new_register(fp);
    printf("Target Reached");
    fclose(fp);
    return 0;
}
