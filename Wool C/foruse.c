#include <stdio.h>

int main(void){
	int a,b;
	printf("数字を入力してください\n");
	scanf("%d",&a);
	b=0;
	for(b=0;b<=100;b=b+a){}
	printf("100超えるのは%dのときです\n",b);
return 0;
}