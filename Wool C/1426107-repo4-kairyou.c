/*配列使用 課題には使わない*/

#include <stdio.h>

int main(void){
	
	int var[]={0x5a12,0x1111,0x5a90,0x5b98,0x0aab},i;
	
	printf("%4x\n%4x\n%4x\n%4x\n%4x\n\n ↓\n\n",var[0],var[1],var[2],var[3],var[4]);
	
	for(i=0;i<5;++i){
		
		if((var[i]&0xff00)==0x5a00){
			
			printf("%4x\n",var[i]);
			
		}else{
			
			printf(" X\n");
			
		}
		
	}
	
	return 0;
	
}