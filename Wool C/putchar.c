#include <stdio.h>

int main(void){
	
	char a='C',b=0x43;
	
	printf("a=%c,a=%2x\n",a,a);
	
	printf("b=%c,b=%2x\n",b,b);
	
	printf("\n関数putcharを使って変数aの出力：");
	
	putchar(a);
	
	printf("\n関数putcharを使って変数bの出力：");
	
	putchar(b);
	
	printf("\n");
	
	return 0;
	
}