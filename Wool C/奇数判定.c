#include <stdio.h>

int main(void){
	int a,b;
	printf("数字を入力してください\n");
	scanf("%d",&a);
	
	b=a%2;
	if(b==1){
		printf("これは奇数です\n");
	}
	else{
		printf("これは偶数です\n");
	}
return 0;
}