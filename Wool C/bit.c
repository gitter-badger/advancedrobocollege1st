#include <stdio.h>

int main(void){
	short a,b,c;
	unsigned short d,e,f;
	
	a=0x00FF;
	b=0xAAAA;
	d=0x00FF;
	e=0xAAAA;
	
	c=a&b;
	printf("a:16�i�� %4x, 10�i�� %d\n",a,a);
	printf("b:16�i�� %4x, 10�i�� %d\n",b,b);
	printf("c:16�i�� %4x, 10�i�� %d\n",c,c);
	
	f=d&e;
	printf("d:16�i�� %4x, 10�i�� %d\n",d,d);
	printf("e:16�i�� %4x, 10�i�� %d\n",e,e);
	printf("f:16�i�� %4x, 10�i�� %d\n",f,f);
	
return 0;
}