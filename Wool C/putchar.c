#include <stdio.h>

int main(void){
	
	char a='C',b=0x43;
	
	printf("a=%c,a=%2x\n",a,a);
	
	printf("b=%c,b=%2x\n",b,b);
	
	printf("\n�֐�putchar���g���ĕϐ�a�̏o�́F");
	
	putchar(a);
	
	printf("\n�֐�putchar���g���ĕϐ�b�̏o�́F");
	
	putchar(b);
	
	printf("\n");
	
	return 0;
	
}