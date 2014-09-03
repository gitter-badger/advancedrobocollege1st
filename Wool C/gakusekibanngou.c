#include <stdio.h>

int main(void){
	
	long a=1,b=1,c=0,d=0;
	
	printf("%d ",a);
	
	printf("%d ",b);
	
	while(c<999999999){
		
			++d;
			
		if(d%8==0){
				
			printf("\n");
			
		
		}
		
		if(d%2==0){
			
			c=a+b;
			
			printf("%d ",c);
			
			a=c;
			
		}else{
			
			c=a+b;
			
			printf("%d ",c);
			
			b=c;
			
		}}
		
return 0;

}