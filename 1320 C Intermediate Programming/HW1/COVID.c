#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 7
int read_doctor_list(char inputfile[20], char filemode[1], char names[][20], char diagnose[])
{
    int i = 0;
    char check[SIZE][20];

    FILE *fp = fopen(inputfile, filemode);

    if (!fp)
    {
        return 0;
    }
    else
    {
        while (fgets(names[i], 20, fp))
        {
            strtok(names[i], "\n");
            fgets(check[i], 20, fp);
            diagnose[i] = check[i][0];
            i++;
        }
        fclose(fp);
    }
    return 1;
}
void band_practice_list(char outputfile[20], char type[], char names[][20], char diagnose[])
{
    int bool = 0;
    FILE *fp = fopen(outputfile, "w");

    printf("Creating list...\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (diagnose[i] == 'P')
        {
            printf("%s: %c...Can't go to practice! :(\n\n", names[i], diagnose[i]);
            if (!strcmp(type, "Positive"))
            {
                if(!bool)
                {
                    fprintf(fp, "--List of %s cases:---\n", type);
                    bool = 1;
                }
                fprintf(fp, "--%s: +%s+\n", names[i], type);
            }
        }
        else if (diagnose[i] == 'N')
        {
            printf("%s: %c...Good to go to practice! :)\n\n", names[i], diagnose[i]);
            if (!strcmp(type, "Negative"))
            {
                if (!bool)
                {
                    fprintf(fp, "--List of %s cases:---\n", type);
                    bool = 1;
                }
                fprintf(fp, "--%s: -%s-\n", names[i], type);
            }
        }
    }
}
int main(int argc, char **argv)
{
    char band_names[SIZE][20];
    char band_diagnose[SIZE];
    int n = read_doctor_list("doctorlist.txt", "r", band_names, band_diagnose);
    if (n)
    {
        band_practice_list("outputp.txt", "Positive", band_names, band_diagnose);
        band_practice_list("outputn.txt", "Negative", band_names, band_diagnose);
    }
}

