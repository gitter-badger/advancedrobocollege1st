#include <stdio.h>

int main(void){
	
	int a,b,c;
	
	a=3;
	b=2;
	c=1;
	
	printf("a=%d, b=%d, c=%d�ł��B\n",a,b,c);
	
	if(a>b){
		if(b>c){
			printf("�����a>b>c�ł��B\n");
		}else{
			if(a>c){
				printf("�����a>c>b�ł��B\n");
			}else{
				printf("�����c>a>b�ł��B\n");
			}}}else{
				if(c>b){
					printf("�����c>b>a�ł��B\n");
				}else{
					if(a>c){
						printf("�����b>a>c�ł��B\n");
					}else{
						printf("�����b>c>a�ł��B\n");
					}}}

return 0;
}