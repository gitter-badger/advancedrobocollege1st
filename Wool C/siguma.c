#include <stdio.h>

int main(void){
	int a,b;
	printf("”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
	scanf("%d",&a);

	for(b=1;b<=100;++b){
		a=b+a;
		printf("%d ",a);
		if(!(b%10)){
			printf("\n");
		}
	}
printf("\nƒ°100‚Ì’l‚Í%d‚Å‚·\n",a);

return 0;
}