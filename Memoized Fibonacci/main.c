#include <stdio.h>
#include <stdlib.h>

int array[30];
int fibo(int f){
	if(f<=1)
	{
		return f;
	}
	else if(array[f]!=-1){
		return array[f];
	}
	else
	{
		array[f]=fibo(f-2)+fibo(f-1);
		return array[f];
	}
}
int main(int argc, char *argv[]) {
	int n;
	for(n=0; n<30; n++)
	{
		array[n]=-1;
	}
	int i;
	
	for(i=0; i<6;i++)
		printf("%d",fibo(i));	
	return 0;
}
