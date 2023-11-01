#include <stdio.h>

void swap( int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void selectionSort( int arr[], int n){
    int i, j, min;
    for( i = 0; i < n-1; i++){
        min = i;
        for(j = i+1; j< n; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i)
            swap(&arr[min], &arr[i]);
    }
}

void print(int arr[], int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d " , arr[i]);
    }
    printf("\n");
}

main(void)
{
    int n, arr[5] = { 4, 432, 543, 542, 4};
    n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    print(arr, n);
}
