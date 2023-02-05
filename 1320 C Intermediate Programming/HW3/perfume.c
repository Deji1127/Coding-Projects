	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<stdbool.h>/*	Ahmed Ibrahim
												1001820005*/
	// This function takes a double pointer as an input-answer by the user to compare with all values of perfumes
	int find_spray_perfume(char answer[],char* perfume_names[], int* size)
	{
		int value = -1;
 // boolean value to exit out of the loop
		for(int i = 0; i<*size; i++)
		{
			while(check)
			{
				if(!strcmp(answer,perfume_names[i]))
				{
					value = i;
					break // exit value incase we find a match
		 		}
		return value;
	}

	// TODO -- Need to modify values to the ounce because it is not adjusting values
	void perfume_spray(int index, char**perf_ptr, int perfume_bottles_oz[],int size)
	{
		int correct = 1;
		while(correct)
		{
				printf("%s\n", perf_ptr[index]);
				printf("Total oz in this bottle of %s: %d", perf_ptr[index], perfume_bottles_oz[index]);
				if(perfume_bottles_oz[index]<2)
				{
					printf("\nNot enough to spray 2oz...You should go buy more.");
					correct = 1;
				}
				else if(perfume_bottles_oz[index]>2)
				{
					printf("\n***SPRAY! Now we have %d oz***", perfume_bottles_oz[index]-2);
					correct = 0;
				}
		}
	}
	void exit_list(char** perf_ptr, int size, char* argv)
	{
			FILE* fp = fopen(argv, "w");
			fprintf(fp, "~~Total perfumes: %d~~\n", size);
			fprintf(fp,"%s-32 oz\n", perf_ptr[0]); //de-referncing a double char ** means I get charcters
			fprintf(fp,"%s-1 oz\n", perf_ptr[1]);
			fprintf(fp, "%s-24 oz\n", perf_ptr[2]);
			fclose(fp);
	}
	int	main(int argc, char**argv)
	{
		char answer[40];
		char* perfume_names[]={"Gucci Flora", "Chanel Chance", "Dior J'adore"};
		char** perf_ptr=perfume_names;

		int	perfume_bottles_oz[]={32,1,24};	 //amount	per	bottle	(e.g.	Gucci	Flora	has	32	oz	etc)
		int	num_times_run_loop=atoi(argv[1]);
		int	size=3,	index;

		for(int	i=0;i<num_times_run_loop;i++)
		{
			printf("Which	perfume to use? ");
			//fgets(answer,	40,	stdin);
			/*strtok(answer,"\n");*/scanf("%s", answer);

			index=find_spray_perfume(answer,perfume_names,&size);
			if(index==-1)
			{
				printf("No	perfume	found	with	this	name...\n");
				exit(0);
			}
			else
			{
				perfume_spray(index, perf_ptr, perfume_bottles_oz, *(&size));
			}
		}
		printf("Exiting...");
		exit_list(&*&*perf_ptr, size, argv[2]);
	}
