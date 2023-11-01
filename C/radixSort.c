#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[], int n){
  int i, max = arr[0];
  for( i = 1; i < n; i++ ){
    if ( arr[i] > max)
      max = arr[i];
  }
  return max;
}

void countingSort(int arr[], int n, int position){
    int *output = (int *)malloc(n*sizeof(int));
    int i, count[10]= {0};
    for (i = 0; i < n; i++){
      count[(arr[i]/position)%10]++;
    }
    for (i = 1; i < 10; i++){
      count[i] += count[i-1];
    }
    for( i = n - 1; i >= 0; i--){
      output[count[(arr[i]/position)%10]-1] = arr[i];
    }
    for( i = 0; i < n; i++){
      arr[i] = output[i];
    }
    free(output);
}

void radixSort(int arr[], int n){
  int max = getMax(arr, n);
  int position;
  for(position = 1; max/position > 0; position *= 10){
    countingSort(arr, n, position);
  }
}
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main(void) {
  int arr[] = {121, 432, -564, 23, 1, -45, 43, -656, 545, -343,788};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixSort(arr, n);
  printArray(arr, n);
}
