#include <stdio.h>

int main(void){
	float a,c;
	int b;
	
	a=3.6
;
	b=a;
	c=a-b;
	if(c<0.5){
		printf("%f���l�̌ܓ������%d�ɂȂ�܂�",a,b);
	}else{
		b=b+1;
		printf("%f���l�̌ܓ������%d�ɂȂ�܂�",a,b);
	}

return 0;
}