#include <stdio.h>

int main(void){
	
	int a,b,c;
	
	printf("a=");
	scanf("%d",&a);
	printf("\n");
	
	c=a;
	
	for(b=1;b<5;++b){
		
		a++;
			
		printf("%d+%d",c,a);
			
		printf("=%d\n",c=c+a);
	}
	
	return 0;
	
}