#include <stdio.h>
#include <stdlib.h>

int b[100]= {0};

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void merge(int arr[], int lower, int mid, int upper)
{
	int i, j, k;
	
	i = lower;
	j = mid + 1;
	k = lower;
	while( i <= mid && j <= upper){ /* */
		if(arr[i] <= arr[j])
		{
			b[k] = arr[i];
			i++;
		}
		else 
		{
			b[k] = arr[j];
			j++;
		}
		k++;
	}
	if ( i > mid)
	{
		while (j <= upper)
		{
			b[k] = arr[j];
			j++;
			k++;
		}
	}
	else
	{
		while( i <= mid){
			b[k] = arr[i];
			i++;
			k++;
		}
	}
	for(k =lower; k <= upper; k++){
		arr[k] = b[k];
	}
}
 
void mergeSort(int arr[], int lower, int upper){
	int mid;
	if(lower < upper)
	{
	    mid = (lower + upper)/2; /* claculate mid element*/
		mergeSort(arr, lower, mid); /* first half of array*/
		mergeSort(arr, mid + 1, upper); /* second half of array*/
		merge(arr, lower, mid, upper);
	}
}


int main(void)
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
