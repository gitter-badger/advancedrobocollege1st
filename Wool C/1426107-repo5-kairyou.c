#include <stdio.h>

int main(){
	
	int enzan,a,b,c,i;
	char d;
	
	while(i){
	
	printf("ŒvŽZ‚µ‚½‚¢Žl‘¥‰‰ŽZ‚ðŒˆ‚ß‚Ä‚­‚¾‚³‚¢\n");
	printf("1. ‰ÁŽZ 2.Œ¸ŽZ 3.æŽZ 4.œŽZ >");
	scanf("%d",&enzan);
	
	switch(enzan){
		
		case 1:
			
			d='+';
			c=a+b;
			break;
			
		case 2:
			
			d='-';
			c=a-b;
			break;
			
		case 3:
		
			d='*';
			c=a*b;
			break;
			
		case 4:
		
			d='/';
			c=a/b;
			break;
			
	}
	
	printf("a %c b ‚ÌŒvŽZ‚ð‚µ‚Ü‚·\n",d);
	printf("a ‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
	scanf("%d",&a);
	printf("b ‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
	scanf("%d",&b);
	printf("%d %c %d = %d‚Å‚·\n",a,d,b,c);
	
	printf("ŒJ‚è•Ô‚µŒvŽZ‚µ‚Ü‚·‚©H\n");
	printf("1. ŒJ‚è•Ô‚· 0.I—¹‚·‚é >");
	scanf("%d",&i);
	printf("\n");
	
	}
	
	return 0;

}