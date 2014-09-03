#include <stdio.h>

int main(void){
	
	long a=1,b=1,c,d,e;
	
	printf("e=");
	scanf("%d",&e);
	
	printf("%d ",a);
	
	printf("%d ",b);
	
	for(d=1;d<e;d++){
			
		if(d%8==0){
			printf("\n");
		}
		
		if(d%2==0){
			printf("%d ",c=a+b);
			a=c;
			
		}else{
			
			printf("%d ",c=a+b);
			b=c;
			
		}}
		
return 0;

}