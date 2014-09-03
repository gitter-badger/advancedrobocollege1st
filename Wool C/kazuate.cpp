#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	
	srand((unsigned int)time(NULL));
	
	int selectnumber=0,computernumber=(rand()%99+1),i=(rand()%5+5);//mynumber,selectcomputer[2]={0,0,99};
	
	printf("２桁以内の数当てゲーム！！\n\n");
	
	printf("チャンスは%d回だ！！当ててみろ！！\n\n",i);
	
	/*add
	
	printf("コンピューターに先に当てられたら負け\n\n");
	
	printf("2桁以内の自分の数字を決めてください >");
	scanf("%d",&mynumber);
	
	//add*/
	
	printf("--------------------------------------------\n\n");
	
	//selectcomputer[0]=(rand()%99+1);
	
	for(;i>0;--i){
	
	printf("数字を入力してください>");
	scanf("%d",&selectnumber);
	
	if(selectnumber==computernumber){
		
		printf("\nあたり！！\n");
		
		return 0;
		
	}
	
	printf("\nはずれ！！\n");
	
	if(i>1){
		
		if(selectnumber<computernumber){
		
		printf("数字は入力した数値より大きいです\n");
		
	}else{
		
		printf("数字は入力した数値より小さいです\n");
		
	}
	
		/*if(computerselect[0]==mynumber){
			
			printf("コンピューターの勝ち\n");
			
		}else{
			
			if(computerselect[0]<mynumber){
				
				if(computerselect[1]<computerselect[0]){
					
					computerselect[1]=computerselect[0];
					
				}else{
					
					computer
				
			}else{*/
		
		printf("あと%d回\n\n",i-1);
	
	}
	
	}
	
	printf("\n答えは%dでした！！\n",computernumber);
	
	return 0;
	
}