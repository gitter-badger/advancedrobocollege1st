#include <stdio.h>

int main(void){
	int a,b,c;
	printf("��������͂��Ă�������\n");
	scanf("%d",&a);
	printf("��������͂��Ă�������\n");
	scanf("%d",&b);
	if(a!=b){
		if(a>b){
			c=a;
			goto print1;
	}
	else{
		c=b;
		goto print2;
	}}
	else{
		goto print3;
	}
print1:
	printf("%d��%d�ł́A%d�̕����ł����ł�\n",a,b,c);
print2:
	printf("%d��%d�ł́A%d�̕����ł����ł�\n",a,b,c);
print3:
	printf("�������l�ł�\n");
return 0;
}