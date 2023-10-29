#include <stdio.h>

void swap(int *p, int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void bubbleSort(int arr[], int n){
    int i, j;
    for( i = 0; i < n - 1; i++){ /* n-1 passes */
        for( j = 0; j < n-1-i; i++){
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

main(void)
{
    int i, n, arr[5] = {4,33,43,25,76};
    n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    for( i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
