#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	float L;
	int a,d1,d2;
	
	printf("aの数値を入力してください")；
	scanf("%d",&a);
	printf("d1の数値を入力してください");
	scanf("%d",&d1);
	printf("dの数値を入力してください");
	scanf("%d",&d2);
	
	L=(2*a)+((M_PI/2)(d2+d1))+((d2-d1)*(d2-d1)/(4*a))
	
	L=L*1000;
	
	L=int(L);
	
	L=L/1000;
	
	printf("L=%f",L);
	
	return 0;
	
}