#include <stdio.h>

int main(void){
	int a,b;
	printf("数字を入力してください\n");
	scanf("%d",&a);

	for(b=1;b<=100;++b){
		a=b+a;
		printf("%d ",a);
		if(!(b%10)){
			printf("\n");
		}
	}
printf("\nΣ100の値は%dです\n",a);

return 0;
}