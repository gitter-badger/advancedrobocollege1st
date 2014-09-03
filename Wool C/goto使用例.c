#include <stdio.h>

int main(void){
	int a,b,c;
	printf("”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
	scanf("%d",&a);
	printf("‚à‚¤ˆê‚Â“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
	scanf("%d",&b);
	if(a!=b){
		if(a>b){
			c=a;
			goto print1;
	}
	else{
		c=b;
		goto print2;
	}}
	else{
		goto print3;
	}
print1:
	printf("%d‚Æ%d‚Å‚ÍA%d‚Ì•û‚ª‚Å‚©‚¢‚Å‚·\n",a,b,c);
print2:
	printf("%d‚Æ%d‚Å‚ÍA%d‚Ì•û‚ª‚Å‚©‚¢‚Å‚·\n",a,b,c);
print3:
	printf("“¯‚¶”’l‚Å‚·\n");
return 0;
}