#include <stdio.h>
#include <stdlib.h>
#define n 10
void quicksort(int array[],int low,int high)
{
	int pivot,i,j,temp;
	if(low<high){
		pivot=low;
		i=low;
		j=high;
		while(i<j)
		{
			while(array[i]<=array[pivot]&&i<high)
				i++;                                 
			while(array[j]>array[pivot])
				j--;
			if(i<j)
			{
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
		
	  	temp=array[pivot];
      	array[pivot]=array[j];
      	array[j]=temp;
    	quicksort(array,low,j-1);
      	quicksort(array,j+1,high);
      	
      }
      
      
}

int main(int argc, char *argv[]) {
	int numbers[n]={3, 1, 9, 44, 35, 0, 45, 19, 2, 33};
	int t;
	for(t=0; t<n; t++)
      	printf("%d-",numbers[t]);
	
	quicksort(numbers,0,(n-1));
	printf("\n quicksort: \n");
	
	for(t=0; t<n; t++)
      	printf("%d-",numbers[t]);
	return 0;
}
