#include <stdio.h>

int main(void){
	
	int a,b,c;
	
	printf("a=",a);
	scanf("%d",&a);
	printf("b=",b);
	scanf("%d",&b);
	printf("c=",c);
	scanf("%d",&c);
		
	printf("a=%d,b=%d,c=%d‚Å‚·\n",a,b,c);
	
	if(a==b){
		if(b==c){
			printf("a=b=c‚Å‚·");
		}else{
			if(b>c){
				printf("a=b>c‚Å‚·");
			}else{
				printf("c>a=b‚Å‚·");
			}
		}
	}else{
		if(a>b){
			if(b==c){
				printf("a>b=c‚Å‚·");
			}else{
				if(a==c){
					printf("a=c>b‚Å‚·");
				}else{
					if(a>c){
						if(b>c){
							printf("a>b>c‚Å‚·");
						}else{
							printf("a>c>b‚Å‚·");
						}
					}else{
						printf("c>a>b‚Å‚·");
					}
				}
			}
		}else{
			if(b==c){
				printf("b=c>a");
			}else{
				if(a==c){
					printf("b>a=c‚Å‚·");
				}else{
					if(a>c){
						printf("b>a>c‚Å‚·");
					}else{
						if(b>c){
							printf("b>c>a‚Å‚·");
						}else{
							printf("c>b>a‚Å‚·");
						}
					}
				}
			}
		}
	}
	return 0;
	
}