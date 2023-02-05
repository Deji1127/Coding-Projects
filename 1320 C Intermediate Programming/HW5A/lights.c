//AHMED IBRAHIM
//1001820005
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Node
{
    char *color;   /*color of the light*/
    int **details; /*holds the brightness and size*/
    struct Node *next;
} Node;

Node *light_info(char *filename) // takes filename and creates linked list of the string of lights. returns the head of the linked list
{
    FILE *fp = fopen(filename, "r"); // opens and reads file

    char line[40];
    char *token;
    Node *head = NULL;
    Node *temp = NULL;
    while (fgets(line, 40, fp))
    {
        token = strtok(line, ",");   // reads the color of the light
        temp = malloc(sizeof(Node)); // allocates size to the linked list
        temp->color = malloc(20);    // allocates size to color char
        strcpy(temp->color, token);  // assigns the first color to the linked list

        temp->details = malloc(sizeof(int *) * 2); // allocates size to details int
        temp->details[0] = malloc(sizeof(int));    // allocates size to first index of int
        temp->details[1] = malloc(sizeof(int));    // allocates size to second index of int

        token = strtok(NULL, ","); // reads the brightness of the light
        int num = atoi(token);
        *(temp->details[0]) = num; // assigns the the brightness to the first index of the details int

        token = strtok(NULL, "\n"); // reads to see if the light is big or small (0 means small and 1 means big)
        int num1 = atoi(token);
        *(temp->details[1]) = num1; // assigns the size to the second index of the int array

        temp->next = head; // moves on to next LL
        head = temp;
    }
    return head;
}
void light_on(Node *h) // takes in the head of the linked list and turns the light on
{
    Node *current = h; // creates a strut variable
    int i = 0;
    printf("\n***Turning lights on:\n");
    while (current) // while not NULL
    {
        while (i < *current->details[0]) // prints as long as its less than the amount held in the first int index
        {
            printf("%c", current->color[0]); // prints the first letter of the color of lights
            i++;
        }
        printf(" ");
        current = current->next; // moves on to the next linked list
    }
    printf("\n");
}
void light_off(Node *h) // takes in the head of the linked list and turns the light off
{
    printf("\n***Turning lights off:\n");
    Node *current = h;
    int i = 0;
    while (current)
    {
        while (i < *(current->details[0])) // prints as long as its less than the amount held in the first int index
        {
            printf("-"); // prints the off switch of each light
            i++;
        }
        printf(" ");
        current = current->next; // moves on to the next linked list
    }
    printf("\n");
}
int main(int argc, char **argv)
{
    Node *lights = light_info(argv[1]); // passes in the first argument and reads the file

    char on_off[15]; // placeholder for on or off

    int on_ticker = 0;  // tracks the status of the on light
    int off_ticker = 0; // tracks the status of the off light
    while (1)
    {
        printf("\n");
        scanf("%s", on_off); // takes in "on" or "off" from the user

        if (!strcmp(on_off, "on") && on_ticker == 0) // if "on" then enter loop
        {
            light_on(lights); // passes in the head struct into the function to turn lights on
            off_ticker = 0; // bit for off
            on_ticker = 1;  // bit for on
        }

        else if (strcmp(on_off, "on") == 0 && on_ticker == 1) // if lights are already on and we're trying to turn it on
        {
            printf("\n--Lights are already on.\n"); // tells user lights are already on
        }

        else if (strcmp(on_off, "off") == 0 && off_ticker == 0) // if "off" then enter loop
        {
            light_off(lights); // passes in the head struct into the function to turn lights on

            off_ticker = 1; // bit for on
            on_ticker = 0;  // bit for off
        }

        else if (strcmp(on_off, "off") == 0 && off_ticker == 1) // if lights are already off and we're trying to turn it off
        {
            printf("\n--Lights are already off.\n"); // tells user lights are already off
        }

        else if (strcmp(on_off, "exit") == 0)
        {
            printf("\nExiting...");
            exit(0);
        }
        else
        {
            printf("\nPlease enter on or off!");
        }
    }
}
