#include <stdio.h>

int main(void){
	float a,c;
	int b;
	
	a=3.6
;
	b=a;
	c=a-b;
	if(c<0.5){
		printf("%fを四捨五入すると%dになります",a,b);
	}else{
		b=b+1;
		printf("%fを四捨五入すると%dになります",a,b);
	}

return 0;
}