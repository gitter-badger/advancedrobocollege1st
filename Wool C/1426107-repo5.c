#include <stdio.h>

int main(){
	
	int enzan,a,b,i;
	
	for(i=1;i<2;){
	
	printf("計算したい四則演算を決めてください\n");
	printf("1. 加算 2.減算 3.乗算 4.除算 >");
	scanf("%d",&enzan);
	
	switch(enzan){
		
		case 1:
		
			printf("a + b の計算をします\n");
			printf("a の値を入力してください >");
			scanf("%d",&a);
			printf("b の値を入力してください >");
			scanf("%d",&b);
			printf("%d + %d = %dです\n",a,b,a+b);
			break;
			
		case 2:
		
			printf("a - b の計算をします\n");
			printf("a の値を入力してください >");
			scanf("%d",&a);
			printf("b の値を入力してください >");
			scanf("%d",&b);
			printf("%d - %d = %dです\n",a,b,a-b);
			break;
			
		case 3:
		
			printf("a * b の計算をします\n");
			printf("a の値を入力してください >");
			scanf("%d",&a);
			printf("b の値を入力してください >");
			scanf("%d",&b);
			printf("%d * %d = %dです\n",a,b,a*b);
			break;
			
		case 4:
		
			printf("a / b の計算をします\n");
			printf("a の値を入力してください >");
			scanf("%d",&a);
			printf("b の値を入力してください >");
			scanf("%d",&b);
			printf("%d / %d = %dです\n",a,b,a/b);
			break;
			
		default:
		
			printf("ちゃんとした数値を入れてください\n\n");
			continue;
			
	}
	
	printf("繰り返し計算しますか？\n");
	printf("1. 繰り返す 2.終了する >");
	scanf("%d",&i);
	printf("\n");
	
	}
	
	return 0;
}