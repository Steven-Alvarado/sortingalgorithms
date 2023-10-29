#!/bin/bash
# Bash program for the above approach
n=10
# read -p "enter the size of the array " n
arr=(9 7 2 5 4 43 23 54 43 8) 
# for(( i = 0 ; i < n ; i++))
# do 
#   read -p "enter the elements of the array" arr[$i]
#done
echo "array before sorting:"
echo ${arr[*]}
#conventions for bash sorting
#arr=(1 2 3 4 5 6)
#echo "${arr[*]}"
# Perform insertion sort to sort the array
for(( i = 1; i < n; i++))
do 
    j=$(( i - 1 ))
    key=${arr[i]}
    while((j >= 0)) && (( arr[j] >= key))
    do
        arr[j+1]=${arr[j]}
        j=$(( j - 1))
    done
    arr[j+1]=$key
done

# Print the sorted array
echo "array after sorting:"
echo ${arr[*]}

