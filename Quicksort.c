#include <stdio.h>
#define n 6
int partition(int array[],int low ,int high)
{
	int pivot=array[high];//pivot is always last element
	int i,j;
	int temp;
	
	j=low;
	for(i=low; i<high; i++)
	{
		if(array[i]<=pivot)
		{
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			j++;

		}
	}
	temp=array[j];
	array[j]=array[high];
	array[high]=temp;
	return j;


}
void quicksort(int array[],int low,int high)
{
	if(low<high)
	{
		int pivot=partition(array,low,high);
		quicksort(array,low,pivot-1);
		quicksort(array,pivot+1,high);

		
	}
}

int main()
{
	int arr[n]={10,7,8,9,1,5};	
	quicksort(arr,0,n-1);
	int i;
	for(i=0; i<n; i++)
	printf("-%d",arr[i]);
}
