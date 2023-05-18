#include <stdlib.h>
#include <stdio.h>

int main()
{

  printf("Running test 5 to test stuff\n");

  char * ptr1 = ( char * ) malloc ( 121 );
  char * ptr2 = ( char * ) malloc ( 2323 );
  char * ptr3 = ( char * ) malloc ( 3434 );
  char * ptr4 = ( char * ) malloc ( 454 );
  char * ptr5 = ( char * ) malloc ( 6000 );
  char * ptr6 = ( char * ) malloc ( 7 );

  free( ptr2 );
  free( ptr5 );

  ptr1 = ptr1;
  ptr4 = ptr4;
  ptr6 = ptr6;

  char * ptr7 = ( char * ) malloc ( 5000 );
  char * ptr8 = ( char * ) malloc (2048);

  ptr7 = ptr7;
  ptr8 = ptr8;

  free( ptr3 );

  return 0;
}
