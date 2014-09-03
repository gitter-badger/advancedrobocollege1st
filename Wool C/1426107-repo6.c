#include <stdio.h>

int main(){
	
	int a[9],i,sum=0,n,b=1;
	float heikin;
	
	while(b==1){
		
		n=0;
		
		while(n<1||n>10){
				
			printf("10人以下の人数を入力してください >");
			scanf("%d",&n);
			
			if(n<1||n>10){
				printf("\nちゃんとした数値を入力してください\n\n");
			}
			
		}
		
		printf("\n");
		
		for(i=0;i<n;++i){
			
			printf("%d人目の点数を入力してください >",i+1);
			scanf("%d",&a[i]);
			sum+=a[i];
			
		}
		
		printf("\n%d人の合計点は%dです\n\n",n,sum);
		
		heikin=(float)sum/n;
		
		printf("%d人の平均点は%fです\n\n",n,heikin);
		
		b=3;
		
		while(b!=1){
			
			printf("繰り返し計算しますか？\n");
			printf("1.はい 2.いいえ >");
			scanf("%d",&b);
			
			if(b==1){
				printf("\n");
			}else if(b==2){
				return 0;
			}else if(b!=1||b!=2){
				printf("\nちゃんとした数値を入力してください\n\n");
			}
	
		}
	
	}
	
	return 0;

}