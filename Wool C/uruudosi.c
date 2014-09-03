#include <stdio.h>

int main(void){
	
	int a,b;
	
	a=2004;
	
	b=0;
	
	if(!(a%4)){
		
		((!(a%100))&&(a%400))?(b=0):(b=1);
		
	}
	
	if(b==1){
		
		printf("%4dは、閏年。\n",a);
		
	}else{
		
		printf("%4dは、平年。\n",a);
	}
	
	return 0;
	
}