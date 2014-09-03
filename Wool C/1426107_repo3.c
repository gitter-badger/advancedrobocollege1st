#include <stdio.h>
int main(void){
	int a=1,b;
	for(b=2;b<=10;b++){
		printf("%2d + %2d",a,b);
		printf(" = %2d\n",a=a+b);
		}
return 0;
}