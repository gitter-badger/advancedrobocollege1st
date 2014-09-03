#include <stdio.h>

int main(){
	
	int enzan,a,b,i;
	
	for(i=1;i<2;){
	
	printf("ŒvŽZ‚µ‚½‚¢Žl‘¥‰‰ŽZ‚ðŒˆ‚ß‚Ä‚­‚¾‚³‚¢\n");
	printf("1. ‰ÁŽZ 2.Œ¸ŽZ 3.æŽZ 4.œŽZ >");
	scanf("%d",&enzan);
	
	switch(enzan){
		
		case 1:
		
			printf("a + b ‚ÌŒvŽZ‚ð‚µ‚Ü‚·\n");
			printf("a ‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
			scanf("%d",&a);
			printf("b ‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
			scanf("%d",&b);
			printf("%d + %d = %d‚Å‚·\n",a,b,a+b);
			break;
			
		case 2:
		
			printf("a - b ‚ÌŒvŽZ‚ð‚µ‚Ü‚·\n");
			printf("a ‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
			scanf("%d",&a);
			printf("b ‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
			scanf("%d",&b);
			printf("%d - %d = %d‚Å‚·\n",a,b,a-b);
			break;
			
		case 3:
		
			printf("a * b ‚ÌŒvŽZ‚ð‚µ‚Ü‚·\n");
			printf("a ‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
			scanf("%d",&a);
			printf("b ‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
			scanf("%d",&b);
			printf("%d * %d = %d‚Å‚·\n",a,b,a*b);
			break;
			
		case 4:
		
			printf("a / b ‚ÌŒvŽZ‚ð‚µ‚Ü‚·\n");
			printf("a ‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
			scanf("%d",&a);
			printf("b ‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
			scanf("%d",&b);
			printf("%d / %d = %d‚Å‚·\n",a,b,a/b);
			break;
			
		default:
		
			printf("‚¿‚á‚ñ‚Æ‚µ‚½”’l‚ð“ü‚ê‚Ä‚­‚¾‚³‚¢\n\n");
			continue;
			
	}
	
	printf("ŒJ‚è•Ô‚µŒvŽZ‚µ‚Ü‚·‚©H\n");
	printf("1. ŒJ‚è•Ô‚· 2.I—¹‚·‚é >");
	scanf("%d",&i);
	printf("\n");
	
	}
	
	return 0;
}