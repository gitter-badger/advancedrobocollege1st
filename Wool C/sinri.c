#include <stdio.h>

int main(void){
		int a,b,c;
	printf("1〜100の中で好きな数字を一つ入力してください\n");
	scanf("%d",&a);
	printf("もう一つ入力してください\n");
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
			printf("あなたは強欲です\n");
			break;
		case 2:
			printf("あなたは強欲じゃありません\n");
			break;
		case 3:
			printf("決められた値を入力してください");
			break;
	}
return 0;
}