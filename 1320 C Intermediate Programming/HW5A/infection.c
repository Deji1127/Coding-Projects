//AHMED IBRAHIM
//1001820005
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef	struct Node
{
    char* country; /*country name*/
    char virus; /*virus*/
    int start_cases; /*number of initial cases reported*/
    float infection_rate; /*daily rate of infection*/
    struct Node* next;
}Node;

Node *read_file() //takes filename and creates linked list of the string of lights
{
    FILE *fp = fopen("infectionstuff.txt", "r"); // opens and reads file

    char line[40]; //string to hold contents of the file
    char *token;
    Node *head = NULL;  //end of a reversed linked list
    Node *temp;
    
    while(fgets(line, 40, fp)) //goes until there are no more lines from the file
    {
        temp = malloc(sizeof(Node)); //gives a size to the temp struct
        
        token = strtok(line, ","); //reads a string until it gets to comma
        temp->country = malloc(strlen(token)+1); //assigns a size to the country variable
        strcpy(temp->country, token);  //the value that was read gets assigned to the country variable
        
        token = strtok(NULL, ","); //starts from the end of what was read and reads to the next comma
        temp->virus = token[0]; //assigns the value of that to virus
        
        token = strtok(NULL, ",");//starts from the end of what was read and reads to the next comma
        temp->start_cases = atoi(token);//assigns the integer value of that to the start_case integer
        
        token = strtok(NULL, "\n");//starts from the end of what was read and reads to the next comma
        temp->infection_rate = atof(token);//assigns the float value of that to the infection_rate float
        temp->next = head; //linkes the list
        head = temp;
        free(temp); //? idk if this works..was a last minute add
    }
    return head;//returns the head of the linked list
}

void print_day(Node* c, int* day, int line)//function to print the details of the countries
{
    Node* current = c;
    if(*day==0) //for the first day
    {
        while(current)
        {
            printf("-%s-cases ",current->country);                  //prints the country
            printf("%d (actual ",current->start_cases);             //prints the start cases
            printf("%f | rate: ",current->start_cases*1.0);         //prints start cases in decimal form
            printf("%.0f%% daily)\n",current->infection_rate*100);  //prints rate of increase in percent form
            current = current->next;                                //moves to next struct
        }
    }
    else                                                            //if not the first day
    {
        while(current)
        {
            printf("-%s-cases ",current->country);                  //prints the country
            current->start_cases = current->start_cases*(current->infection_rate+1.0);//calculates and prints the current cases
            printf("%d (actual ",current->start_cases);                 //prints start cases in decimal form
            printf("%f | rate: ",current->start_cases*1.0);             //prints rate of increase in percent for 
            if(current->start_cases>=line)                              //if cases are getting too high
            {            
                printf("%.0f%% daily) Careful...\n",current->infection_rate*100);//prints rate of increase in percent form and warning
            }
            else                                      //otherwise
            {
                printf("%.0f%% daily)\n",current->infection_rate*100);//prints rate of increase in percent for
            }
            current = current->next;  //next struct
        }
    }
}

void send_aid(Node*c, int* workers, int* day, int sum)//allows to move to next day and assign workers
{                                                     //could've made two functions
    Node* current = c;                                  //one for next say and one for assigning workers
    char next[1]; //to check for enter(next day) or s(assign aid workers)
    scanf("%s", next);
    while(current)//while not NULL or while not false(0)
    {
        if(next=="\n") //if they say enter, printout next day info
        {
            *day = *day+1; 
            printf("\n\n--%d (Aid Workers Available: %d)",*day, *workers);//shows how many workers are available
            print_day(current,day,sum);                                   //prints out day information using previous func
        }
        else if(next=='s')//if the want to assign workers
        {
            char aids[50];//char to hold which couontry they want
            printf("\nWhich country to send aid to and how many? ");
            scanf("%s", &aids);//reads in country
            printf(" ");
            int send;//holds how many workers to send
            scanf("%d", &send);//reads in workers
            if(*workers>send && *workers%send==0) //if there are enough wkrs(workers>send)  
            {                                       //AND workers are assigned in multiples of 10(workers%send==0)
                *workers = *workers-send; //take away the workers assigned from total workers
                current->infection_rate = current->infection_rate/send;//infection rate gets changed to (rate/wrks)
                printf("\nRate for %s is now %f",current->infection_rate);
            }
            else if(*workers<send)//if not enough wrks
            {
                printf("\nWe don't have that many aid workers available.");
                printf(" We currently only have %d",*workers);
            }
            else if(*workers%send!=0)//if wrks isnt a multiple of 10
            {
                printf("\nMot a valid number of aid workers. Enter a multiple of 10");
            }
            else if(*workers==0)//if no more workers at all
            {
                printf("\n\nNo more aid workers available. Exiting program...");
                exit(0);
            }
        }
        current = current->next;
    }
}

int main(int argc, char**argv)
{
    Node* country = read_file();
    int workers = 50;
    int day = 0;
    int num = argv[2];
    printf("--Day %d(Aid Workers Available: %d)\n\n",day,workers);
    while(true)
    {
        print_day(country,&workers,num);
        send_aid(country,&workers,&day,num);
    }
}


