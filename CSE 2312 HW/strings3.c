// CSE 2312 Computer Org and Assembly Language Programming
// strings3 example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <stdint.h>   // C99 uintX_t and intX_t types

// contatenate strFrom to the end of strTo
extern void strCat(char strTo[], const char strFrom[]);

// return a substring starting at offset with max length
extern void strMid(char strTo[], const char strFrom[], uint32_t offset, uint32_t length);

int main(void)
{
    char str[] = "Hello world";
    char str2[20];
    char str3[20] = "ABC ";
    char match = 'o';
    uint32_t n = 2;
    int result;
    uint32_t ofs = 4; 
    uint32_t len = 20;

    printf("str3 = %s\n", str);
    printf("str = %s\n", str);
    strCat(str3, str);
    printf("str3 = %s\n", str3);

/*        
    strMid(str2, str, ofs, len);
    printf("ofs = %u\n", ofs);
    printf("len = %u\n", len);
    printf("str = \"%s\"\n", str);
    printf("str2 = \"%s\"\n", str2);
*/

    return EXIT_SUCCESS;
}


