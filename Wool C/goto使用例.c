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
			goto print1;
	}
	else{
		c=b;
		goto print2;
	}}
	else{
		goto print3;
	}
print1:
	printf("%dと%dでは、%dの方がでかいです\n",a,b,c);
print2:
	printf("%dと%dでは、%dの方がでかいです\n",a,b,c);
print3:
	printf("同じ数値です\n");
return 0;
}