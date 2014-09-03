#include <stdio.h>

int main(void){
	
	unsigned int var1=0x5a12,var2=0x1111,var3=0x5a90,var4=0x5b98,var5=0x0aab,musk=0xff00;
	
	printf("‚P‚Ui”‚ÌãˆÊ‚QŒ…‚ª \"5a\" ‚©”»’f‚µ‚Ü‚·\n\n%4x\n%4x\n%4x\n%4x\n%4x\n\n «\n\n",var1,var2,var3,var4,var5);
	
	if((var1&musk)==0x5a00){
		printf("%4x\n",var1);
	}else{
		printf(" X\n");
	}
	
	if((var2&musk)==0x5a00){
		printf("%4x\n",var2);
	}else{
		printf(" X\n");
	}
		
	if((var3&musk)==0x5a00){
		printf("%4x\n",var3);
	}else{
		printf(" X\n");
	}
		
	if((var4&musk)==0x5a00){
		printf("%4x\n",var4);
	}else{
		printf(" X\n");
	}
		
	if((var5&musk)==0x5a00){
		printf("%4x\n",var5);
	}else{
		printf(" X\n");
	}
	
	return 0;
	
}