#include <stdio.h>

int main(){
	
	int enzan,a,b,i;
	
	for(i=1;i<2;){
	
	printf("�v�Z�������l�����Z�����߂Ă�������\n");
	printf("1. ���Z 2.���Z 3.��Z 4.���Z >");
	scanf("%d",&enzan);
	
	switch(enzan){
		
		case 1:
		
			printf("a + b �̌v�Z�����܂�\n");
			printf("a �̒l����͂��Ă������� >");
			scanf("%d",&a);
			printf("b �̒l����͂��Ă������� >");
			scanf("%d",&b);
			printf("%d + %d = %d�ł�\n",a,b,a+b);
			break;
			
		case 2:
		
			printf("a - b �̌v�Z�����܂�\n");
			printf("a �̒l����͂��Ă������� >");
			scanf("%d",&a);
			printf("b �̒l����͂��Ă������� >");
			scanf("%d",&b);
			printf("%d - %d = %d�ł�\n",a,b,a-b);
			break;
			
		case 3:
		
			printf("a * b �̌v�Z�����܂�\n");
			printf("a �̒l����͂��Ă������� >");
			scanf("%d",&a);
			printf("b �̒l����͂��Ă������� >");
			scanf("%d",&b);
			printf("%d * %d = %d�ł�\n",a,b,a*b);
			break;
			
		case 4:
		
			printf("a / b �̌v�Z�����܂�\n");
			printf("a �̒l����͂��Ă������� >");
			scanf("%d",&a);
			printf("b �̒l����͂��Ă������� >");
			scanf("%d",&b);
			printf("%d / %d = %d�ł�\n",a,b,a/b);
			break;
			
		default:
		
			printf("�����Ƃ������l�����Ă�������\n\n");
			continue;
			
	}
	
	printf("�J��Ԃ��v�Z���܂����H\n");
	printf("1. �J��Ԃ� 2.�I������ >");
	scanf("%d",&i);
	printf("\n");
	
	}
	
	return 0;
}