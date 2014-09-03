#include <stdio.h>

int main(void){
	short a,b,c,d,e,f,g,h;
	
	a=0x00FF;
	b=0xAAAA;
	c=0xFFFF;
	
	d=a&b;
	e=a|b;
	f=a^b;
	g=~b;
	h=c^b;
	
	