#include <stdio.h>

int main(void){
	int a;
	printf("”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ >");
	scanf("%d",&a);
	if((a%2)==0){
		if((a%6)==0){
			printf("\n%d‚Í2‚Ì”{”‚Å‚ ‚èA6‚Ì”{”‚Å‚·\n",a);
		}else{
			printf("\n%d‚Í2‚Ì”{”‚ÅA6‚Ì”{”‚Å‚Í‚ ‚è‚Ü‚¹‚ñ\n",a);
	}}
	else{
		printf("\n%d‚Í2‚Ì”{”‚Å‚àA6‚Ì”{”‚Å‚à‚ ‚è‚Ü‚¹‚ñ\n",a);
	}
	return 0;
}