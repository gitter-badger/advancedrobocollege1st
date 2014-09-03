#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int i;

  srand( (unsigned int)time( NULL ) );

  for( i=0; i<100; i++ ){
    if( i % 4 == 0 ) printf( "\n" );
    printf( "%d\t", ((rand()%5)+1)+((rand()%5)+1) );  /* 0`99 */
  }
  
  printf("\n--------------\n\n");
  
  for( i=0; i<100; i++ ){
    if( i % 4 == 0 ) printf( "\n" );
    printf( "%d\t", (rand()%10)+1 );  /* 0`99 */
  }

  return 0;
}