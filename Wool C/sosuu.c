#include <stdio.h> 
 
int main(void) 
{ 
int i,j,yakusuu; 
 
for(i=1;i<=1000;i++) 
{ 
yakusuu=0; 
for(j=1;j<=i;j++) 
{ 
if(i%j==0) yakusuu++; 
} 
 
if(yakusuu==2) printf("%d ",i); 
} 
 
printf("\n"); 
 
return 0; 
}