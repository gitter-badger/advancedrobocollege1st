#include <stdio.h>

int main(void){
	
	int a,b,c;
	
	printf("a=",a);
	scanf("%d",&a);
	printf("b=",b);
	scanf("%d",&b);
	printf("c=",c);
	scanf("%d",&c);
		
	printf("a=%d,b=%d,c=%d�ł�\n",a,b,c);
	
	if(a==b){
		if(b==c){
			printf("a=b=c�ł�");
		}else{
			if(b>c){
				printf("a=b>c�ł�");
			}else{
				printf("c>a=b�ł�");
			}
		}
	}else{
		if(a>b){
			if(b==c){
				printf("a>b=c�ł�");
			}else{
				if(a==c){
					printf("a=c>b�ł�");
				}else{
					if(a>c){
						if(b>c){
							printf("a>b>c�ł�");
						}else{
							printf("a>c>b�ł�");
						}
					}else{
						printf("c>a>b�ł�");
					}
				}
			}
		}else{
			if(b==c){
				printf("b=c>a");
			}else{
				if(a==c){
					printf("b>a=c�ł�");
				}else{
					if(a>c){
						printf("b>a>c�ł�");
					}else{
						if(b>c){
							printf("b>c>a�ł�");
						}else{
							printf("c>b>a�ł�");
						}
					}
				}
			}
		}
	}
	return 0;
	
}