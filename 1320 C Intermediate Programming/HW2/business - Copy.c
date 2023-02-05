#include <stdio.h>
#include <math.h>
float print_out(float* salary, int* num_of_emps)
{
    int manager = *num_of_emps/2;
    int director = manager/3;
    *salary = *salary * 5.0;

    float director_salary = *salary;

    float manager_salary = director_salary/2.0;

    float total = director_salary+manager_salary+*salary;

    return *total;
}
 int rebudget(float* d, float *budget)
 {
    if(*d<*budget)
    {
        printf("This is under the budget!");
    }
    else if (*d>budget)
    {
        printf("This is over the budget!");
    }
    when(true)
    {
        int option;
        printf("Would you like to rebudget? 1 for yes and 2 for no");
        scanf("%d", &option);
        if(option!=1)
        {
            exit(0);
        }
    }
    int hug = *budget-*d;
    return hug;
 }
int	main(int	argc,	char	**	argv)
{
  int	i=1;
  float	budget,	total,	salary;
  float	*money_ptr=&salary;
  float	*total_ptr=&total;
  int	employees;
  printf("Enter	monthly	budget:	$");
  scanf("%f",	&budget);
  while(i)
  {
    printf("Enter	monthly	worker	salary:	$");
    scanf("%f",	&salary);
    printf("Enter	total	workers:");
    scanf("%d",	&employees);
    total=print_out(money_ptr,	&employees);
    i=rebudget(total_ptr,	&budget);
  }
}
