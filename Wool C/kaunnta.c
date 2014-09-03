#include <stdio.h>

int main(void){
	int n=0;
	int a=1;
	
	while(n++<10){
		a=a*n;
		printf("%d!=%d\n",n,a);
	}
	printf("10!‚Í%d‚Å‚·B\n",a);

return 0;
}