#include <stdio.h>

void tasizan(int x, int y, int z){
	
	int w=x+y+z;
	
	printf("%d + %d + %d = %d\n",x,y,z,w);
	
}

void kakezan(int x, int y, int z){
	
	int w=x*y*z;
	
	printf("%d * %d * %d = %d\n",x,y,z,w);
	
}

int main(void){
	
	int a,b,c;
	
	printf("”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n\n");
	
	printf("a=");
	scanf("%d",&a);
	
	printf("b=");
	scanf("%d",&b);
	
	printf("c=");
	scanf("%d",&c);
	
	tasizan(a,b,c);
	kakezan(a,b,c);
	
	return 0;
	
}