#include <stdio.h>

int main(void){
		int a,b,c;
	printf("1�`100�̒��ōD���Ȑ���������͂��Ă�������\n");
	scanf("%d",&a);
	printf("��������͂��Ă�������\n");
	scanf("%d",&b);
	if(a+b>=100){
		c=1;
	}
	if(a+b<100){
		c=2;
	}
	if(0>=a){
		c=3;
	}
	if(a>100){
		c=3;
	}
	if(b<=0){
		c=3;
	}
	if(b>100){
		c=3;
	}
	switch(c){
		case 1:
			printf("���Ȃ��͋��~�ł�\n");
			break;
		case 2:
			printf("���Ȃ��͋��~���Ⴀ��܂���\n");
			break;
		case 3:
			printf("���߂�ꂽ�l����͂��Ă�������");
			break;
	}
return 0;
}