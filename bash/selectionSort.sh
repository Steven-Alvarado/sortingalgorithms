#!/bin/bash
read -p "enter the size of the array: " n
for((i=0;i<n;i++))
do
    read -p "enter elements in the array: " arr[$i]
done
#logic for selection sort
for (( i = 0; i < n -1; i++))
do
	min=$i
	for((j = i + 1; j< n; j++))
	do
		if(( arr[j] < arr[min]))
		then
			min=$j
		fi
	done
	if((min != i))
	then
		temp=${arr[min]}
		arr[min]=${arr[i]}
		arr[i]=$temp
	fi
done

#printing sorted array
echo "printing sorted array"
echo "${arr[*]}"
