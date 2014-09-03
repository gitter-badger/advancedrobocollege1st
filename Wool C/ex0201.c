#include <stdio.h>

int main(void){
	int a,b;
	a=100;
	b=8;
	printf("***** %d‚Æ%d‚ÌŒvŽZ *****\n",a,b);
	printf("%3d +%3d = %3d\n",a,b,a+b);
	printf("%3d -%3d = %3d\n",a,b,a-b);
	printf("%3d *%3d = %3d\n",a,b,a*b);
	printf("%3d /%3d = %3d\n",a,b,a/b);
	printf("%3d /%3d = %3d ¥¥¥ %3d\n",a,b,a/b,a%b);
	return 0;
}