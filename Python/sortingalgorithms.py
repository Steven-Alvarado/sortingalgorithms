class Solution:
    def swap(self, arr, i1, i2):
        temp = arr[i1]
        arr[i1] = arr[i2]
        arr[i2] = temp

    def bubbleSort(self, arr: list, n: int) -> list:
        for i in range (n-1):
            for j in range(n):
                if arr[j] > arr[j+1]:
                    self.swap(arr, j, j+1)

    def selectionSort(self, arr: list, n: int) -> list:
        for i in range(n-1):
            min_val = i
            for j in range(i+1, n):
                if(arr[j] < arr[min_val]):
                    min_val = j
            if min_val != i:
                self.swap(arr, min_val, i)

    def insertionSort(self, arr: list, n: int)->list:
        for i in range(1, n):
            j = i - 1
            key = arr[i]
            while j >= 0 and arr[j] >= key:
                arr[j+1] = arr[j]
                j-=1
            arr[j+1] = key

    def countingSort(self, arr: list, n: int, position: int)->list:
        output = [0] * n
        count = [0] * 10
        for i in range(n):
            count[(arr[i]//position)%10]+=1
        for i in range(1, 10):
            count[i]+=count[i-1]
        for i in range(n -1, -1, -1):
            output[count[(arr[i]//position)%10]-1] = arr[i]
            count[(arr[i]//position)%10]-=1
        for i in range(n):
            arr[i] = output[i]

    def getMax(self, arr: list, n: int) -> int:
        max_val = arr[0]
        for i in range (1, n):
            if max_val < arr[i]:
                max_val = arr[i]
        return max_val

    def radixSort(self, arr: list, n: int)-> list:
        position = 1
        max_val = self.getMax(arr, n)
        while max_val//position > 0:
            self.countingSort(arr, n, position)
            position += 10



solution=Solution()
#radix sort
print('radix sort\nwhat is the size of the array')
n = int(input())
arr = []
print('enter the element(s) in the array')
for i in range(n):
    element = int(input())
    arr.append(element)

print("Array before sorting:")
print(arr)
solution.radixSort(arr, n)
print("Array after sorting:" )
print(arr)

#insertion sort
print('\ninsertion sort\nwhat is the size of the array')
n = int(input())
arr = []
print('enter the element(s) in the array')
for i in range(n):
    element = int(input())
    arr.append(element)

print("Array before sorting:")
print(arr)
solution.insertionSort(arr, n)
print("Array after sorting:" )
print(arr)

#bubble sort
print('\nbubble sort\nwhat is the size of the array')
n = int(input())
arr = []
print('enter the element(s) in the array')
for i in range(n):
    element = int(input())
    arr.append(element)

print("Array before sorting:")
print(arr)
solution.bubbleSort(arr, n)
print("Array after sorting:" )
print(arr)

#selection sort
print('\nselection sort\nwhat is the size of the array')
n = int(input())
arr = []
print('enter the element(s) in the array')
for i in range(n):
    element = int(input())
    arr.append(element)

print("Array before sorting:")
print(arr)
solution.selectionSort(arr, n)
print("Array after sorting:" )
print(arr)