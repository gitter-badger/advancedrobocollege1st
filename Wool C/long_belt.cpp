#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	float L[3];
	float a,d1,d2;
	
	printf("a‚Ì”’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ a=");
	scanf("%f",&a);
	printf("d1‚Ì”’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ d1=");
	scanf("%f",&d1);
	printf("d2‚Ì”’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ d2=");
	scanf("%f",&d2);
	
	L[0]=(2*a)+((M_PI/2)*(d2+d1))+(((d2-d1)*(d2-d1))/(4*a));
	
	L[1]=L[0]-int(L[0]);
	
	L[2]=L[0]-L[1];
	
	if((L[1]+0.0005)>1.0) L[1]=L[1]+0.0005;
	else ;
	
	L[3]=(L[1]*1000-int(L[1]*1000))/1000;
	
	L[1]=L[1]-L[3];
	
	L[0]=L[2]+L[1];
	
	printf("L=%f\n",L[0]);
	
	return 0;
	
}