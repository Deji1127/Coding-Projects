// CSE 2312 Computer Org and Assembly Language Programming
// add32 example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types

extern uint32_t add32(uint32_t a, uint32_t b);

// extern means function instance is not in this object... in another object (C or asm)
// linker resolves the externs in C with .def or .global in ASM code
// not an assembly thing... it is a C keyword used to tell linker 
// this function must be found in another object
// example extern printf(char* format, ....) this line of code in stdio.h
// extern means in the c library object

/*
uint32_t add32(uint32_t a, uint32_t b)
{
    return a + b;
}
*/

int main(void)
{
    uint32_t x = 2;
    uint32_t y = 3;
    uint32_t z = add32(x, y);
    printf("x = %"PRIu32"\n", x);
    printf("y = %"PRIu32"\n", y);
    printf("z = %"PRIu32"\n", z);
        
    return EXIT_SUCCESS;
}


