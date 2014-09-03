#include <stdio.h>

int main(void){
	
	int a,b,c,d,e,f;
	
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);
	
	d=a;
	
	if(d<b){
		
		d=b;
		e=a;
		
	}else{
		
		e=b;
	}
	
	if(d<c){
		
		f=e;
		e=d;
		d=c;
		
	}else if(e<c){
		
		d=e;
		e=c;
		
	}else{
		
		f=c;
		
	}
	
	printf();
	
	return 0;
}