#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	
	srand((unsigned int)time(NULL));
	
	int selectnumber=0,computernumber=(rand()%99+1),i=(rand()%5+5);//mynumber,selectcomputer[2]={0,0,99};
	
	printf("�Q���ȓ��̐����ăQ�[���I�I\n\n");
	
	printf("�`�����X��%d�񂾁I�I���ĂĂ݂�I�I\n\n",i);
	
	/*add
	
	printf("�R���s���[�^�[�ɐ�ɓ��Ă�ꂽ�畉��\n\n");
	
	printf("2���ȓ��̎����̐��������߂Ă������� >");
	scanf("%d",&mynumber);
	
	//add*/
	
	printf("--------------------------------------------\n\n");
	
	//selectcomputer[0]=(rand()%99+1);
	
	for(;i>0;--i){
	
	printf("��������͂��Ă�������>");
	scanf("%d",&selectnumber);
	
	if(selectnumber==computernumber){
		
		printf("\n������I�I\n");
		
		return 0;
		
	}
	
	printf("\n�͂���I�I\n");
	
	if(i>1){
		
		if(selectnumber<computernumber){
		
		printf("�����͓��͂������l���傫���ł�\n");
		
	}else{
		
		printf("�����͓��͂������l��菬�����ł�\n");
		
	}
	
		/*if(computerselect[0]==mynumber){
			
			printf("�R���s���[�^�[�̏���\n");
			
		}else{
			
			if(computerselect[0]<mynumber){
				
				if(computerselect[1]<computerselect[0]){
					
					computerselect[1]=computerselect[0];
					
				}else{
					
					computer
				
			}else{*/
		
		printf("����%d��\n\n",i-1);
	
	}
	
	}
	
	printf("\n������%d�ł����I�I\n",computernumber);
	
	return 0;
	
}