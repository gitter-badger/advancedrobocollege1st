#include <stdio.h>

int main(){
	
	int enzan,a,b,c,i;
	char d;
	
	while(i){
	
	printf("�v�Z�������l�����Z�����߂Ă�������\n");
	printf("1. ���Z 2.���Z 3.��Z 4.���Z >");
	scanf("%d",&enzan);
	
	switch(enzan){
		
		case 1:
			
			d='+';
			c=a+b;
			break;
			
		case 2:
			
			d='-';
			c=a-b;
			break;
			
		case 3:
		
			d='*';
			c=a*b;
			break;
			
		case 4:
		
			d='/';
			c=a/b;
			break;
			
	}
	
	printf("a %c b �̌v�Z�����܂�\n",d);
	printf("a �̒l����͂��Ă������� >");
	scanf("%d",&a);
	printf("b �̒l����͂��Ă������� >");
	scanf("%d",&b);
	printf("%d %c %d = %d�ł�\n",a,d,b,c);
	
	printf("�J��Ԃ��v�Z���܂����H\n");
	printf("1. �J��Ԃ� 0.�I������ >");
	scanf("%d",&i);
	printf("\n");
	
	}
	
	return 0;

}