#include <stdio.h>

int main(void){
	
	int a,b,c;
	
	printf("a=",a);
	scanf("%d",&a);
	printf("b=",b);
	scanf("%d",&b);
	printf("c=",c);
	scanf("%d",&c);
		
	printf("a=%d,b=%d,c=%dです\n",a,b,c);
	
	if(a==b){
		if(b==c){
			printf("a=b=cです");
		}else{
			if(b>c){
				printf("a=b>cです");
			}else{
				printf("c>a=bです");
			}
		}
	}else{
		if(a>b){
			if(b==c){
				printf("a>b=cです");
			}else{
				if(a==c){
					printf("a=c>bです");
				}else{
					if(a>c){
						if(b>c){
							printf("a>b>cです");
						}else{
							printf("a>c>bです");
						}
					}else{
						printf("c>a>bです");
					}
				}
			}
		}else{
			if(b==c){
				printf("b=c>a");
			}else{
				if(a==c){
					printf("b>a=cです");
				}else{
					if(a>c){
						printf("b>a>cです");
					}else{
						if(b>c){
							printf("b>c>aです");
						}else{
							printf("c>b>aです");
						}
					}
				}
			}
		}
	}
	return 0;
	
}