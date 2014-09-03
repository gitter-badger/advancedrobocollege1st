#include <stdio.h>

int main(void){
	short a,b,c;
	unsigned short d,e,f;
	
	a=0x00FF;
	b=0xAAAA;
	d=0x00FF;
	e=0xAAAA;
	
	c=a&b;
	printf("a:16進数 %4x, 10進数 %d\n",a,a);
	printf("b:16進数 %4x, 10進数 %d\n",b,b);
	printf("c:16進数 %4x, 10進数 %d\n",c,c);
	
	f=d&e;
	printf("d:16進数 %4x, 10進数 %d\n",d,d);
	printf("e:16進数 %4x, 10進数 %d\n",e,e);
	printf("f:16進数 %4x, 10進数 %d\n",f,f);
	
return 0;
}