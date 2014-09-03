#include <stdio.h>

int main(void){
	
	short a,b,c,j;
	unsigned short d,e,f;
	
	a=0x00FF;
	b=0xAAAA;
	c=0x00FF;
	j=0xFFFF;
	
	c=a*b;
	
	printf("a:16進数 %4x, 10進数 %6d\n",a,a);
	printf("b:16進数 %4x, 10進数 %6d\n",b,b);
	printf("c:16進数 %4x, 10進数 %6d\n",c,c);
	
	printf("\n%4x, %6d, %o\n",j,j,j);
	
	return 0;
	
}