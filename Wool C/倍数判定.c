#include <stdio.h>

int main(void){
	int a;
	printf("数字を入力してください >");
	scanf("%d",&a);
	if((a%2)==0){
		if((a%6)==0){
			printf("\n%dは2の倍数であり、6の倍数です\n",a);
		}else{
			printf("\n%dは2の倍数で、6の倍数ではありません\n",a);
	}}
	else{
		printf("\n%dは2の倍数でも、6の倍数でもありません\n",a);
	}
	return 0;
}