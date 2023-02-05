//Ahmed Ibrahim
//1001820005
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dragons//Creating a structure that holds values for each dragon
{
	char name[50];
	char colors[3];
	int heads;
	int tails;

} dragon;
void dragon_info(dragon* d)
{

	int i=0;
	char* token;
	char answer[250];

	scanf("%s",answer);  //Using redirection to get the input data for each dragon
	strtok(answer,",");  // Getting rid of the "start" phrase

	while(i<4)   //Getting values for each dragon
	{
		token = strtok(NULL,",");  //getting the name of
		strcpy(d[i].name, token);

		token = strtok(NULL,",");  //getting the first color
        d[i].colors[0] = token[0];

        token = strtok(NULL,",");  //getting the second color
        d[i].colors[1] = token[0];

        token = strtok(NULL,",");  //getting the third color
        d[i].colors[2] = token[0];

		token = strtok(NULL,",");  //getting the number of heads
        d[i].heads = atoi(token);

        token = strtok(NULL,",");  //getting the number of tails
        d[i].tails = atoi(token);

		i++;// incrementing
	}
}
void color(char* color, dragon *d)  //prints out the dragon that has the same color as specified in main
{
    if(*color == 'b')  //only if the color from main is going to change
    {
        printf("***All the blue dragons:***\n");
        for(int i = 0; i<4; i++)
        {
            if(d[i].colors[0] == *color)  //if the letter from colors at a certain index is the same as entered
            {
                printf("\n%s is blue", d[i].name); //printout the name at that index
            }
            else if(d[i].colors[1] == *color)
            {
                printf("\n%s is blue", d[i].name);
            }
            else if(d[i].colors[2] == *color)
            {
                printf("\n%s is blue", d[i].name);
            }
        }
    }
    else if(*color == 'r')  //only if the color from main is going to change
    {
        printf("***All the red dragons:***\n");
        for(int i = 0; i<4; i++)
        {
            if(d[i].colors[0] == *color)
            {
                printf("\n%s is red", d[i].name);
            }
            else if(d[i].colors[1] == *color)
            {
                printf("\n%s is red", d[i].name);
            }
            else if(d[i].colors[2] == *color)
            {
                printf("\n%s is red", d[i].name);
            }
        }
    }
    else if(*color == 'w')//only if the color from main is going to change
    {
        printf("***All the white dragons:***\n");
        for(int i = 0; i<4; i++)
        {
            if(d[i].colors[0] == *color)
            {
                printf("\n%s is white", d[i].name);
            }
            else if(d[i].colors[1] == *color)
            {
                printf("\n%s is white", d[i].name);
            }
            else if(d[i].colors[2] == *color)
            {
                printf("\n%s is white", d[i].name);
            }
        }
    }
    else if(*color == 'g')//only if the color from main is going to change
    {
        printf("***All the green dragons:***\n");
        for(int i = 0; i<4; i++)
        {
            if(d[i].colors[0] == *color)
            {
                printf("\n%s is green", d[i].name);
            }
            else if(d[i].colors[1] == *color)
            {
                printf("\n%s is green", d[i].name);
            }
            else if(d[i].colors[2] == *color)
            {
                printf("\n%s is green", d[i].name);
            }
        }

    }
    else if(*color == 'y')//only if the color from main is going to change
    {
        printf("***All the yellow dragons:***\n");
        for(int i = 0; i<4; i++)
        {
            if(d[i].colors[0] == *color)
            {
                printf("\n%s is yellow", d[i].name);
            }
            else if(d[i].colors[1] == *color)
            {
                printf("\n%s is yellow", d[i].name);
            }
            else if(d[i].colors[2] == *color)
            {
                printf("\n%s is yellow", d[i].name);
            }
        }
    }
}
int	main (int argc,	char **argv)
{
    dragon total[4];
    dragon_info(total);
    char c='b';
    color(&c, total);
}
