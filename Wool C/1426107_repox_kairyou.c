#include <stdio.h>

int main(void){
	
	int a,b,c;
	
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);
	
	printf("�ua=%d, b=%d, c=%d�ł��B\n",a,b,c);
	
	if(a>b){
		if(b>c){
			printf("�����a > b > c�ł��B�v\n");
		}else{
			if(a>c){
				printf("�����a > c > b�ł��B�v\n");
			}else{
				printf("�����c > a > b�ł��B�v\n");
			}}}else{
				if(c>b){
					printf("�����c > b > a�ł��B�v\n");
				}else{
					if(a>c){
						printf("�����b > a > c�ł��B�v\n");
					}else{
						printf("�����b > c > a�ł��B�v\n");
					}}}

return 0;
}