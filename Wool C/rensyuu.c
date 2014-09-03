#include <stdio.h>

int main(void){
	
	int *a=100;
	
	printf("%x,%x",&a,&a+1);
	
	return 0;
	
}