/*ahmed ibrahim 
1001820005
gcc.exe (MinGW.org GCC-6.3.0-1) 6.3.0
Windows
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <limits.h>

int dirSpace(char *dir) 
{
    int localSum = 0;
    struct dirent *directory;
    struct stat file;
    DIR *folder = opendir(dir);

    if (folder == NULL)
    {
        perror("opendir");
        return 0;
    }

    while ((directory = readdir(folder)) != NULL) //while directory is open
    {
        if (strcmp(directory->d_name, ".") == 0 || strcmp(directory->d_name, "..") == 0) //ignore .. and .
        { 
            continue;
        }

        char file_Path[PATH_MAX];
        snprintf(file_Path, sizeof(file_Path), "%s/%s", dir, directory->d_name); //join path

        if (stat(file_Path, &file) == -1)
        {
            // perror("stat");
            continue;
        }

        if (S_ISDIR(file.st_mode))
        {
            localSum += dirSpace(file_Path); // call func recusively
        }
        else if (S_ISREG(file.st_mode))
        {
            localSum += (int)file.st_size; //get size
        }
    }
    closedir(folder);
    return localSum;
}

int main()
{
    char targetDir[PATH_MAX]; //target directory
    if (getcwd(targetDir, sizeof(targetDir)) == NULL)
    {
        perror("getcwd");
        return 1;
    }

    printf("%d\n", dirSpace(targetDir)); //
}