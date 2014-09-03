#include <stdio.h>

int main(void){
	
	int a[2][2],b[2][2],c,i,j;
	
	printf("2行2列の行列要素を入力してください。\n");
	for(i=0;i<2;++i){
		for(j=0;j<2;++j){
			printf("%1d 行 %1d 列 の要素:",i+1,j+1);
			scanf("%d",&a[i][j]);
			
		}
		
	}
	
	printf("\n");
	
	c=a[0][0]*a[1][1]-a[0][1]*a[1][0];
	
	if(c){
		
		b[0][0]=a[1][1];
		b[0][1]=-a[0][1];
		b[1][0]=-a[1][0];
		b[1][1]=a[0][0];
		
		printf("|%3d %3d|-1   1  |%3d %3d|\n",a[0][0],a[0][1],b[0][0],b[0][1]);
		printf("|       |   =--- |       |\n");
		printf("|%3d %3d|    %d  |%3d %3d|\n",a[1][0],a[1][1],c,b[1][0],b[1][1]);
	}else{
		
		printf("この行列の逆行列は存在しません。\n");
	}
	
return 0;

}