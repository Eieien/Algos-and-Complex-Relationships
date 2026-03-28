---
Date Created: "0314"
Status: "#idea"
topics: "[[Algorithms and Complexity]]"
tags:
  - "#Sorting_algorithms"
---
# Comb Sort
Like shell sort is an improvement of insertion sort, Comb sort is an improvement of bubble sort
- Has a gap and a shrink size factor of `1.3` to shrink the gaps
- Very similar to shell sort

# Process
1. Get the gap by dividing the size of the array with the shrink factor
2. Get the sublist starting from the gap and the elements that are gaps apart
3. shift to the right and compare sublists until shifting reaches the end
4. Reduce the gap by dividing the current gap with the shrink factor
	- If gap < 1: gap = 1
5. Repeat steps 2-4 until the gap reaches 1
6. If gap == 1 do bubble sort

# Implementation
```
void CombSort(int arr[], int len){

    int gap = len;
    bool swapped = true;

    while (gap > 1 || swapped){
        
        gap = floor(gap/1.3);
        if(gap < 1) gap = 1;
        swapped = false;
        
        for(int i = gap; i < len; i++){
            
            if(arr[i] < arr[i - gap]){
                int temp = arr[i];
                arr[i] = arr[i - gap];
                arr[i - gap] = temp;
                swapped = true;
            }
        }
    }
}
```

# Stability: Unstable
Similar to shell sort, identical elements can jump over each other when they are comparing other elements

[[Unstable Sorting Algorithm]]

---
# References