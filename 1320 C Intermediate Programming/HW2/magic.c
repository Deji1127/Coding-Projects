#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
check_tickets_valid(int all_tickets, int max_ticket, int	size_of_tickets);
{
  int counter = 0;
  for (int i = 0; i<5; i++)
  {
    if(all_tickets[i]<400)
    {
      printf("Ticket is welcome");
      counter++
    }
    else
    {
      printf("You're not allowed in the show. please leave");
    }
  }
  return counter;
}
find_magic_number(int*	all_tickets,	int*	num_valid_tickets,	int**	size_of_tickets);
{
  for (int i = 0; i<5; i++)
  {
    if (all_tickets[0]<all_tickets[i])
    {
      all_tickets[0] = all_tickets[i];
    }
  }
  int magic_ticket = all_ticket[0]%num_valid_tickets;
  FILE *fp=fopen(magic.txt, "w");
  fprintf(fp,"%d", magic_ticket);
  fclose(fp);
}
int main(int argc, char**argv)
{
		int	max_ticket_number=atoi(argv[1]);
		int	ticket_numbers[5]={120,625,345,700,300};
		int	size_tickets=5;
		int*	ptr_size=&size_tickets;
		int	total_valid=check_tickets_valid(ticket_numbers,	&max_ticket_number,	&ptr_size);
		printf("Total	valid	tickets:	%d\n\n",	total_valid);
		int*	ptr_total=&total_valid;
		if	(1<total_valid)
		{
				int	magic_number=find_magic_number(ticket_numbers,	ptr_total,	&ptr_size);
				printf("Magic	number	is:	%d\n",	magic_number);
		}
  }
