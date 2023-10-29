#include <stdio.h>

void insertionSort(int arr[], int n){
    int i, j, key;
    for( i = 1; i < n; i++){
        j = i-1;
        key = arr[i];
        while( j >= 0 && arr[j] >= key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(void)
{
    int n, i, arr[6] = {43, 32, 54, 32, 42, 23};
    n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printf("{");
    for (i = 0; i < n; i++){
        printf(" %d ", arr[i]);
    }
    printf("}\n");
    return 0;
}
