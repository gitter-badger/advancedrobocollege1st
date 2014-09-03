#include <stdio.h>

int main(void){
	
	int a,b,c;
	
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);
	
	printf("「a=%d, b=%d, c=%dです。\n",a,b,c);
	
	if(a>b){
		if(b>c){
			printf("よってa > b > cです。」\n");
		}else{
			if(a>c){
				printf("よってa > c > bです。」\n");
			}else{
				printf("よってc > a > bです。」\n");
			}}}else{
				if(c>b){
					printf("よってc > b > aです。」\n");
				}else{
					if(a>c){
						printf("よってb > a > cです。」\n");
					}else{
						printf("よってb > c > aです。」\n");
					}}}

return 0;
}