#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	
	srand((unsigned int)time(NULL));
	
	int a,b,c;
	
	//char d[]={'�O�['},e[]={'�`���L'},f[]={'�p�['};
	
	printf("����񂯂񂵂܂�\n");
	
	while(1){
	
	printf("�P�D�O�[ �Q�D�`���L �R�D�p�[ >");
	scanf("%d",&a);
	
	b=rand()%3+1;
	
	c=a-b;
	
	//printf("%s VS %s\n",d[a-1],d[b-1]);
	
	if(1<=a&&a<=3){
	
	if(c==0){
		
		printf("�������ł�\n");
		continue;
		
	}else if(c==-1||c==2){
		
		printf("�����ł�\n");
		break;
		
	}else if(c==1||c==-2){
		
		printf("�����ł�\n");
		break;
		
	}
	
	}else{
		
		printf("�����Ɠ��͂���\n\n");
		continue;
		
	}
	
	}
	
	return 0;
	
}