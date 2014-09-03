#include <stdio.h>

int main(void){
	
	char *p[]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
	
	int i,j;
	
	for(i=0;i<12;++i){
		printf("%2d ŒŽF%s\n",i+1,p[i]);
		}
	
	for(i=0;i<12;++i){
		
		j=-1;
		
		do{
			++j;
			printf("%8x",p[i]+j);
		}while(*(p[i]+j)!='\0');
		printf("\n");
		j=-1;
		do{
			++j;
			printf("    %c ",*(p[i]+j));
		}while(*(p[i]+j)!='\0');
		printf("\n");
	}
}
			