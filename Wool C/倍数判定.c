#include <stdio.h>

int main(void){
	int a;
	printf("��������͂��Ă������� >");
	scanf("%d",&a);
	if((a%2)==0){
		if((a%6)==0){
			printf("\n%d��2�̔{���ł���A6�̔{���ł�\n",a);
		}else{
			printf("\n%d��2�̔{���ŁA6�̔{���ł͂���܂���\n",a);
	}}
	else{
		printf("\n%d��2�̔{���ł��A6�̔{���ł�����܂���\n",a);
	}
	return 0;
}