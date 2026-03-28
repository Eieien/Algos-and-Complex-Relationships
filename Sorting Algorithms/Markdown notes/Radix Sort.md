---
Date Created: "0321"
Status: "#idea"
topics: "[[Algorithms and Complexity]]"
tags:
  - Sorting_algorithms
---
# Radix Sort
A non-comparative algorithm that groups elements by their one-digit positions into an array of arrays. The one-digit process will start from ones to tenths to hundreds until the array is sorted. Also uses a stable sorting algorithm like counting sort to sort the elements within the groups

Can be counting Sort but with a slight variation?

# Process
1. Create an array with size being the base of the number system (most common is base 10)
2. Find the biggest element and count how many digits it has since it will be the basis of the amount of iterations needed for the unit place digits
3. Group the elements with it's one's digit by distributing them to the created array
4. Do Counting Sort to each group to sort them
5. Redistribute the elements back to the original array
6. Repeat Step 3 - 5 but instead of using one's digit, you use the tenths digit and so on as the basis for distributing them. Repeat until the unit place is bigger than the max number
7. Array is sorted

# Implementation
```
void countingRadixSort(int arr[], int len, int exp){

    int output[len];
    int count[10] = {0};

    for(int i = 0; i < len; i++){
        count[(arr[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1]; 
    }

    for(int i = len - 1; i >= 0; i--){
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i < len; i++){
        arr[i] = output[i];
    }

}

void RadixSort(int arr[], int len){
    
    int max = arr[0];
    for(int i = 0; i < len; i++){
        if(max < arr[i]) max = arr[i];
    }
    
    for(int exp = 1; max / exp > 0; exp *= 10){
        countingRadixSort(arr, len, exp);
    }

}
```

---
# References