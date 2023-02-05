//Ahmed Ibrahim
//1001820005
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct orders
{
    char name[25];
    char payment;
    int items_ordered;
    float amount_spent;
    int order_status;
} order;
void input_orders(order *o, int	size, char*filename)
{
    FILE* fp = fopen(filename, "r");//read the file (given on the command line)
    char line[100];
    char* token;
    int i = 0;
    if(fp==NULL)
    {
        printf("File not found!");
        exit(0);
    }
    else
    {
        while(i<size)
        {
            fgets(line,40,fp);
            token = strtok(line, ",");
            strcpy(o[i].name, token);
            token = strtok(NULL, ",");
            o[i].payment = token[0];
            token = strtok(NULL, ",");
            int num = atoi(token);
            o[i].items_ordered = num;
            token = strtok(NULL, ",");
            int num1 = atoi(token);
            o[i].amount_spent = num1;
            token = strtok(NULL, "\n");
            int num2 = atoi(token);
            o[i].order_status = num2;
            i++;
        }
    }
}
void print_out(int status, order*o, int size)
{
    printf("Do you want to see all orders to fill or orders already completed? Type fill or completed fill\n");
    char fil[25];
    scanf("%s", fil);
    int i = 0;
    int j = 0;
    if(strcmp(fil,"completed")!=0)
    {
        printf("Need to fill:\n");
        while(i<size)
        {
            if(o[i].order_status==status)
            {
                printf("%s\n",o[i].name);
            }
            i++;
        }
    } 
    else if(strcmp(fil,"fill")!=0)
    {
        printf("Already filled:\n");
        while(j<size)
        {
            if(o[j].order_status!=status)
            {
                printf("%s\n",o[j].name);
            }
            j++;
        }
    }
}
int	pick_next(order	*o,	int	size_order)
{
    int retur;
    char yes_no;
    for(int i = 0; i<size_order; i++)
    {
        if(o[i].order_status==2)
        {
            printf("\nNext order to fill: %s\n", o[i].name);
            printf("Go ahead and fulfill this order? y or n\n");
            scanf("%s", yes_no);
            if(yes_no=='y')
            {
                printf("Fulfilled!");
                o[i].order_status = 1;
                retur = i;
                return retur;
            }
            else if(yes_no=='n')
            {
                printf("Not fulfilled");
                retur = -1;
            }
        }
    }
    return retur;
}
void output_file(char*filename, order *o, int size_order)
{
    FILE* fp = fopen(filename, "r+");
    for(int i = 0; i<size_order; i++)
    {
       printf("%s, %c, %d, %d, %0.2f, %d\n", o[i].name,o[i].payment,o[i].items_ordered,o[i].amount_spent,o[i].order_status); 
    }
}
int main(int argc, char**argv)
{
    int num = atoi(argv[1]);
    order* total = malloc(sizeof(order)*num);
    input_orders(total,num,argv[2]);
    printf("***Buongiorno Chef Bartolomeo!***");
    while(true)
    {
        printf("\nWhat to do?\n");
        printf("1. print out orders\n");
        printf("2. pick next order to fulfill\n");
        printf("3. exit\n");
        int scan;
        scanf("%d", &scan);
        int status = 2;
        if(scan==1)
        {
            print_out(status,total,num);
        }
        else if(scan==2)
        {
            pick_next(total,num);
        }
        else if(scan==3)
        {
            printf("Saving information...Ciao\n");
            output_file(argv[2],total,num);
            exit(0);
        }
    }
}