#include <stdio.h>

int main(void){
	
	int a,b,n;
	
	printf("求めたいn年後はいくつですか\n");
	scanf("%d",&b);
	
	
	printf("数字を入力してください\n");
	scanf("%d",&a);
	
	n=0;
	
	while(++n<b){
		a=a+a/20;
	}
	
	printf("利子＝%d\n",a);
	
return 0;
}