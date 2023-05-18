#include <stdio.h>  /* printf, scanf, NULL */
#include <stdlib.h> /* malloc, free, rand */

int main()
{
    int i = 8;
    int n;
    char *buffer;

    printf("String is 8 letters long ");

    buffer = (char *)malloc(i + 1);
    if (buffer == NULL)
    {
        exit(1);
    }

    for (n = 0; n < i; n++)
    {
        buffer[n] = rand() % 26 + 'a';
    }

    buffer[i] = '\0';

    printf("Random string: %s\n", buffer);
    free(buffer);

    return 0;
}
