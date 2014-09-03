#include <stdio.h>

int main(void){
		int a,b,c;
	printf("1`100‚Ì’†‚ÅD‚«‚È”Žš‚ðˆê‚Â“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
	scanf("%d",&a);
	printf("‚à‚¤ˆê‚Â“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
	scanf("%d",&b);
	if(a+b>=100){
		c=1;
	}
	if(a+b<100){
		c=2;
	}
	if(0>=a){
		c=3;
	}
	if(a>100){
		c=3;
	}
	if(b<=0){
		c=3;
	}
	if(b>100){
		c=3;
	}
	switch(c){
		case 1:
			printf("‚ ‚È‚½‚Í‹­—~‚Å‚·\n");
			break;
		case 2:
			printf("‚ ‚È‚½‚Í‹­—~‚¶‚á‚ ‚è‚Ü‚¹‚ñ\n");
			break;
		case 3:
			printf("Œˆ‚ß‚ç‚ê‚½’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢");
			break;
	}
return 0;
}