#include <stdio.h>

int main(void){
	
	char a[100],b[100];
	
	printf("姓と名に空白を入れて名前を入力してください >");
	
	scanf("%s %s",&a,&b);
	
	printf("\n");
	
	printf("%s %s",b,a);
	
	return 0;
	
}