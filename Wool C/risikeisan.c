#include <stdio.h>

int main(void){
	
	int a,b,n;
	
	printf("‹‚ß‚½‚¢n”NŒã‚Í‚¢‚­‚Â‚Å‚·‚©\n");
	scanf("%d",&b);
	
	
	printf("”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
	scanf("%d",&a);
	
	n=0;
	
	while(n++<b){
		a=a+a/20;
	}
	printf("Œ³—˜%d\n",a);
	
return 0;
}