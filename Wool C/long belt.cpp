#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	float L;
	int a,d1,d2;
	
	printf("a�̐��l����͂��Ă�������")�G
	scanf("%d",&a);
	printf("d1�̐��l����͂��Ă�������");
	scanf("%d",&d1);
	printf("d�̐��l����͂��Ă�������");
	scanf("%d",&d2);
	
	L=(2*a)+((M_PI/2)(d2+d1))+((d2-d1)*(d2-d1)/(4*a))
	
	L=L*1000;
	
	L=int(L);
	
	L=L/1000;
	
	printf("L=%f",L);
	
	return 0;
	
}