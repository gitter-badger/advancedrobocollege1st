#include <stdio.h>

int main(){
	
	int a[9],i,sum=0,n,b=1;
	float heikin;
	
	while(b==1){
		
		n=0;
		
		while(n<1||n>10){
				
			printf("10�l�ȉ��̐l������͂��Ă������� >");
			scanf("%d",&n);
			
			if(n<1||n>10){
				printf("\n�����Ƃ������l����͂��Ă�������\n\n");
			}
			
		}
		
		printf("\n");
		
		for(i=0;i<n;++i){
			
			printf("%d�l�ڂ̓_������͂��Ă������� >",i+1);
			scanf("%d",&a[i]);
			sum+=a[i];
			
		}
		
		printf("\n%d�l�̍��v�_��%d�ł�\n\n",n,sum);
		
		heikin=(float)sum/n;
		
		printf("%d�l�̕��ϓ_��%f�ł�\n\n",n,heikin);
		
		b=3;
		
		while(b!=1){
			
			printf("�J��Ԃ��v�Z���܂����H\n");
			printf("1.�͂� 2.������ >");
			scanf("%d",&b);
			
			if(b==1){
				printf("\n");
			}else if(b==2){
				return 0;
			}else if(b!=1||b!=2){
				printf("\n�����Ƃ������l����͂��Ă�������\n\n");
			}
	
		}
	
	}
	
	return 0;

}