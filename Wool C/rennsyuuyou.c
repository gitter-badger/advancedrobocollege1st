#include <stdio.h>

int main(void){
	
	int a,b,n;
	
	printf("���߂���n�N��͂����ł���\n");
	scanf("%d",&b);
	
	
	printf("��������͂��Ă�������\n");
	scanf("%d",&a);
	
	n=0;
	
	while(++n<b){
		a=a+a/20;
	}
	
	printf("���q��%d\n",a);
	
return 0;
}