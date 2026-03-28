---
Date Created: "20260314"
Status: "#idea"
topics: "[[Algorithms and Complexity]]"
tags:
  - Sorting_algorithms
---
# Counting Sort
A Non-comparison algorithm that sorts the array using a frequency/count array and getting the correct position of each element using that frequency/count array
# Process
1. Find the max element of the input array
2. Create a count/frequency array with the size of the max element
3. Loop through the input array and increment the index (using the element value as index) in the frequency array by 1
4. Get the prefix/cumulative sum `arr[i + 1] += arr[i]` of each position in the frequency array
5. Create an output array with the same size as the input array
6. starting from the **last element of the input array**, get the value of the **frequency array** with the **selected element of the input array**, and minus it by 1, then place the selected element of the input array in the output array
	- `output[freqArr[arr[i]] - 1] = arr[i]`
7. Decrement the value of the selected element in the frequency array by 1
	- `freqArr[arrr[i]] -= 1`
8. Repeat step 6 until you reach the end of the input array
9. Transfer elements of input array to output array or return output array

# Implementation
```
void countingSort2(int arr[], int len){
    int max = arr[0];

    // find the max
    for(int i = 0; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    // output array
    int* output = malloc(sizeof(int) * len);
    // frequency array
    int* freqArr = calloc(max + 1, sizeof(int));
    // Increase index count on frequency array
    for(int i = 0; i < len; i++){
        freqArr[arr[i]]++;
    }
    // Cumsum/prefixsum
    for(int i = 0; i < max; i++){
        freqArr[i + 1] += freqArr[i];
    }
    // Counting Sort Process
    for(int i = len - 1; i >= 0; i--){
        output[freqArr[arr[i]] - 1] = arr[i];
        freqArr[arr[i]]--;
    }
    // output to input arr
    for(int i = 0; i < len; i++){
        arr[i] = output[i];
    }
    free(freqArr);
    free(output);
}
```
# Non-comparison Algorithm
Sort element without comparing values

# Advantages
- Good for small datasets
# Disadvantages
- Cannot handle negative numbers unless you modify it
- Space Complexity is not optimal for larger ranges/larger max values

---
# References