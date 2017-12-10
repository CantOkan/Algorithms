#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define EXECUTION_COUNT	100000
#define n 6


float elapsed_time(struct timeval t0, struct timeval t1);
void Selection()
{
	struct timeval t0;
	struct timeval t1;
	gettimeofday(&t0, 0);
	int array[n]={2,7,4,1,5,3};
	int i,j,min,z;
	for(z=0; z<EXECUTION_COUNT; z++)
	{
	for(i=0; i<n-1; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		{
			if(array[min]>array[j])
			{
				min=j;
			}
		}
		int temp=array[i];
		array[i]=array[min];
		array[min]=temp;	
	}
	}
	gettimeofday(&t1, 0);
	printf(" %f milliseconds.\n", elapsed_time(t0, t1));
	int y;
	for(y=0; y<n; y++)
	{
		printf("-%d",array[y]);
	}
}
void BubbleSort()
{
	struct timeval t0;
	struct timeval t1;
	gettimeofday(&t0, 0);

	int array[n]={2,7,4,1,5,3};
	int i,j;
	int z;
	for(z=0; z<EXECUTION_COUNT; z++)
	{

	for(i=0; i<(n-1); i++)
	{
		for(j=0; j<(n-1); j++)// you can also add i <(n-1-i);
		{
			if(array[j]>array[j+1])
			{
				int temp=array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
		}
	}
	
	}
	gettimeofday(&t1, 0);
	printf(" %f milliseconds.\n", elapsed_time(t0, t1));
	int y;
	for(y=0; y<n; y++)
	{
		printf("-%d",array[y]);
	}
}
void InsertionSort()
{
	struct timeval t0;
	struct timeval t1;
	gettimeofday(&t0, 0);
	
	int array[n]={2,7,4,1,5,3};
	int i,j,key,z;
	for(z=0; z<EXECUTION_COUNT; z++)
	{
	for(i=1; i<n ;i++)
	{
		
		key=array[i];
		j=i-1;
		while(j>=0 && array[j]>key)
		{
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=key;
	}
	}
	gettimeofday(&t1, 0);
	printf(" %f milliseconds.\n", elapsed_time(t0, t1));
	int y;
	for(y=0; y<n; y++)
	{
		printf("-%d",array[y]);
	}
}

int main(int argc, char *argv[]) {	
	printf("Selecetion sort");
	Selection();
	printf("\nBubble sort");
	BubbleSort();
	printf("\nInsertion sort");
	InsertionSort();
	return 0;
}
float elapsed_time(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
