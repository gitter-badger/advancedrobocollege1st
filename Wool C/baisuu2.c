#include <stdio.h>

int main(void){
	int a,b;
	printf("数字を入力してください\n");
	scanf("%d",&a);
	b=0;
	while(b<=100){
		b=b+a;
	}
	printf("100を初めて超える%dの倍数、%dです\n",a,b);

return 0;
}