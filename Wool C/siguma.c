#include <stdio.h>

int main(void){
	int a,b;
	printf("��������͂��Ă�������\n");
	scanf("%d",&a);

	for(b=1;b<=100;++b){
		a=b+a;
		printf("%d ",a);
		if(!(b%10)){
			printf("\n");
		}
	}
printf("\n��100�̒l��%d�ł�\n",a);

return 0;
}