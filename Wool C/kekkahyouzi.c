#include <stdio.h>

int main(void){
	
	int a,b,n;
	
	printf("数字を入力してください\n");
	scanf("%d",&a);
	
	b=11;
	
	for(n=0;n<4;n++){
		printf("\n%d*%d=%d\n",a,b,a*b);
		a=a*b;
	}
return 0;
}