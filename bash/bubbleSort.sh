#/bin/bash
# Sorting the array in Bash 
# using Bubble sort

# Static input of Array
read -p "enter the size of the array: " n
for ((i = 0; i < n; i++))
do
    read -p "enter the elements in the array: " arr[$i]
done
echo "Array in original order"
echo ${arr[*]}

# Performing Bubble sort 
for(( i = 0; i < n-1; i++))
do
    for(( j = 0; j < n - 1 - i; j++))
    do
        if(( arr[j] > arr[j+1]))
        then
            temp=${arr[j]}
            arr[j]=${arr[((j+1))]}
            arr[j+1]=$temp
        fi
    done
done

echo "Array in sorted order :"
echo ${arr[*]}
