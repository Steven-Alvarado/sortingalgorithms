/* Type your code here, or load an example. */
#include <stdio.h>

int getMax(int arr[], int n){
    int i, max = arr[0];
    for (i = 1; i < n; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void insertionSort(int arr[], int n){
    int i, j, key;
    for(i = 1; i < n; i++){
        j = i - 1;
        key = arr[i];
        while( j >= 0 && arr[j] >= key ){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

countingSort(int arr[], int n, int position){
    int *output = (int *)malloc(n*sizeof(int));
    int i, count[10] = {0};
    for (i = 0; i < n ; i++){
        count[(arr[i]/position)%10]++;
    }
    for( i = 1; i < 10; i++){
        count[i]=count[i-1];
    }
    for(i = n -1; i > 0; i--){
        output[count[(arr[i]/position)%10]-1]= arr[i];
        count[(arr[i]/position)%10]--;
    }
    for(i = 0; i < n; i++){
        arr[i] = output[i];
    }
    free(output);
}

void radixSort(int arr[], int n){
    int max = getMax(arr, n);
    int position;
    for ( position = 1; max/position > 0; position *= 10){
        countingSort(arr, n, position);
    }
}

int main(void){
    int i, n, element;
    printf("what is the size of the array: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in the array: \n");
    for ( i = 0; i < n; i++){     
        scanf("%d", &element);
        arr[i] = element;
    }
    printf("Array before sorting: \n{");
    for ( i = 0; i < n; i++){
        printf("%d ", arr[i]); 
    }
    printf("}\n");
    insertionSort(arr, n);
    printf("Array after sorting:\n{");
    for ( i = 0; i < n; i++){
        printf("%d ", arr[i]); 
    }
    printf("}\n");
}