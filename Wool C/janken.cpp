#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	
	srand((unsigned int)time(NULL));
	
	int a,b,c;
	
	//char d[]={'グー'},e[]={'チョキ'},f[]={'パー'};
	
	printf("じゃんけんします\n");
	
	while(1){
	
	printf("１．グー ２．チョキ ３．パー >");
	scanf("%d",&a);
	
	b=rand()%3+1;
	
	c=a-b;
	
	//printf("%s VS %s\n",d[a-1],d[b-1]);
	
	if(1<=a&&a<=3){
	
	if(c==0){
		
		printf("あいこです\n");
		continue;
		
	}else if(c==-1||c==2){
		
		printf("勝ちです\n");
		break;
		
	}else if(c==1||c==-2){
		
		printf("負けです\n");
		break;
		
	}
	
	}else{
		
		printf("ちゃんと入力しろ\n\n");
		continue;
		
	}
	
	}
	
	return 0;
	
}