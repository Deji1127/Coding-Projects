	/*Ahmed Ibrahim
	  1001820005
		mail.c*/
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define SIZE 5

	typedef struct mailbox
	{
		char first_name[20]; //first name
		char last_name[20]; //last name
		int apt_num; //apt number
		char all_mail[2][400]; //mail when delivered (max 2    letters)…copy the string of    the    letter here
		int pieces_of_mail;    //number of    letters currently in mailbox
	}MAILBOX;

	int set_info(char* file_name, MAILBOX all_residents[]) //finished
	{
		FILE* fp = fopen(file_name, "r");
		printf("Reading all resident info from %s\n", file_name);
		if(fp!=NULL)
		{
				char line[40];
				int i = 0;
				char* token;
				while(i<5)
				{
						fgets(line,40,fp);
						token = strtok(line," ");
						strcpy(all_residents[i].first_name, token);
						token = strtok(NULL,",");
						strcpy(all_residents[i].last_name, token);
						token = strtok(NULL,",apt ");
						all_residents[i].apt_num = atoi(token);
						token = strtok(NULL,"\n");
						all_residents[i].pieces_of_mail = atoi(token);
						printf("Creating mailbox for %s %s in %d. Currently has %d letter(s).\n", all_residents[i].first_name, all_residents[i].last_name, all_residents[i].apt_num, all_residents[i].pieces_of_mail);
						i++;
				}
				printf("All mailboxes created!\n\n************\n\n");
				fclose(fp);
				return 1;
		}
		else if(fp==NULL)
		{
				printf("File didn't open. Exiting...\n");
				return 0;
		}
	}

	int deliver_mail(char* otherfile_name, MAILBOX all_resident[], int size)
	{
		int total_extra=0;
		printf("~~Delivering mail...\n");
		FILE* fp =  fopen(otherfile_name, "r");
		if(fp!=NULL)
		{
				char line[150];
				char* token;

				while(!feof(fp))
				{
						fgets(line, 150, fp);
						printf("Delivering to %s", line);
						token = strtok(line, ":");
						int apt = atoi(token);
						char* mail = strtok(NULL, "\n");

						for(int i = 0; i < size; i++)
						{
								if(!strcmp(all_resident[i].last_name, token) || all_resident[i].apt_num == apt)
								{
										all_resident[i].pieces_of_mail++;
										if(all_resident[i].pieces_of_mail == 2)
										{
												printf("%d currently has %d letter(s). Mailbox is now full.\n\n", all_resident[i].apt_num, all_resident[i].pieces_of_mail);
												strcpy(all_resident[i].all_mail[1], mail);
										}
										else if(all_resident[i].pieces_of_mail > 2)
										{
												int extra = all_resident[i].pieces_of_mail-2;
												total_extra=total_extra+extra;
												printf("Sorry, mailbox is full. %d undelivered letter(s).\n\n", extra);
										}
										else if(all_resident[i].pieces_of_mail < 2)
										{
												printf("%d currently has %d letter(s).\n\n", all_resident[i].apt_num, all_resident[i].pieces_of_mail);
												strcpy(all_resident[i].all_mail[0], mail);
										}
								}
						}
				}
		}
		else if(fp==NULL)
		{
				printf("File didn't open. Exiting...\n");
				return 0;
		}
		printf("\n************\n\n");
		fclose(fp);
		return total_extra;
	}

	void exit_program(char* argv, MAILBOX residents[], int struct_num)
	{
		printf("Exiting program...mail report being saved to file %s...", argv);
		FILE* fp = fopen(argv, "w");
		for(int i=0; i < struct_num; i++)
		{
				if(residents[i].pieces_of_mail <= 2)
				{
						fprintf(fp, "%s, %s: %d\n", residents[i].last_name, residents[i].first_name, residents[i].pieces_of_mail);
				}
				else if(residents[i].pieces_of_mail > 2)
				{
						residents[i].pieces_of_mail = 2;
						fprintf(fp, "%s, %s: %d\n", residents[i].last_name, residents[i].first_name, residents[i].pieces_of_mail);
				}
		}
		fclose(fp);
	}

	int main(int argc, char**argv)
	{
		MAILBOX all_residents[5];

		if(set_info(argv[1],all_residents))
		{
				int mail_info=deliver_mail(argv[2], all_residents, 5); //function args: filename, array of structs, # of structs

				if(!mail_info)
				{
						printf("All mail was successfully delievered!\n");
				}
				else
				{
						printf("Some mailboxes were full, number of undelivered letters: %d\n", mail_info);
				}

				char name[20];
				while(strcmp(name, "exit"))
				{
						printf("\nEnter resident's last name or apt number: ");
						fgets(name, 20, stdin);
						strtok(name, "\n");
						int apt=atoi(name);
						for(int i = 0; i < 5; i++)
						{
								if((!strcmp(name, all_residents[i].last_name))||all_residents[i].apt_num==apt)
								{
										printf("%s %s, resident in apt %d, has %d letter(s):\n", all_residents[i].first_name, all_residents[i].last_name, all_residents[i].apt_num, mail_info);
										if(all_residents[i].pieces_of_mail>2)
										{
												all_residents[i].pieces_of_mail=2;
										}
										for(int q=0; q<all_residents[i].pieces_of_mail; q++)
										{
												printf("%d.%s\n", q+1, all_residents[i].all_mail[q]);
										}
										printf("\n");
								}
						}
				}
				exit_program(argv[3], all_residents,5); //function args: filename, array of structs, # of structs
		}
	}
