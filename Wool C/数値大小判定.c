#include <stdio.h>

int main(void){
	int a,b,c;
	printf("数字を入力してください\n");
	scanf("%d",&a);
	printf("もう一つ入力してください\n");
	scanf("%d",&b);
	if(a!=b){
		if(a>b){
			c=a;
			printf("%dと%dでは、%dの方がでかいです\n",a,b,c);;
	}
	else{
		c=b;
		printf("%dと%dでは、%dの方がでかいです\n",a,b,c);
	}}
	else{
		printf("同じ数値です\n");
	}
return 0;
}