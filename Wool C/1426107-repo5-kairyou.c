#include <stdio.h>

int main(){
	
	int enzan,a,b,c,i;
	char d;
	
	while(i){
	
	printf("計算したい四則演算を決めてください\n");
	printf("1. 加算 2.減算 3.乗算 4.除算 >");
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
	
	printf("a %c b の計算をします\n",d);
	printf("a の値を入力してください >");
	scanf("%d",&a);
	printf("b の値を入力してください >");
	scanf("%d",&b);
	printf("%d %c %d = %dです\n",a,d,b,c);
	
	printf("繰り返し計算しますか？\n");
	printf("1. 繰り返す 0.終了する >");
	scanf("%d",&i);
	printf("\n");
	
	}
	
	return 0;

}