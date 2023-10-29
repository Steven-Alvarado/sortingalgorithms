

#include <stdio.h>


void swap(int *p, int *q) {
  int temp = *p;
  *p = *q;
  *q = temp;
}

int partition(int arr[], int lower, int upper){
    int pivot = arr[lower];
    int start = lower;
    int end = upper;
    while (start < end)
    {
        while(arr[start] <= pivot)
        start++;
        while(arr[end] > pivot)
        end--;
        if (start < end)
        swap(&arr[start],&arr[end]);
    }
    swap(&arr[lower], &arr[end]);
    return end;
}

void quickSort( int arr[], int lower, int upper){
    int location;
    if (lower < upper)
    {
        location = partition(arr, lower, upper);
        quickSort(arr, lower, location - 1);
        quickSort(arr, location + 1, upper);
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
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("Unsorted Array\n");
  printArray(data, n);
  

  quickSort(data, 0, n - 1);
  
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}
