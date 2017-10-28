#include<stdio.h>
#include<stdlib.h>
#define Size 10
int main(){
int *p;
p=(int*)malloc(10*sizeof(int));
int i=0;
if(p==NULL){ 
printf("this array is empty");
}
while(p[i] == '\0')
{
scanf("%d",&p[i]);
i++;
}
for(i=0; i<10;	 i++){
printf("%d\n",p[i]);
}
free(p);
}
