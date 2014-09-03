#include <stdio.h>
#include <windows.h>

int main(){
	
	int i;
	
	for(i=5;i>0;--i){
		
		printf("%d\n",i);
		
		Sleep(1000);
		
	}
	
	printf("countdown end\n");
	
	return 0;
	
}