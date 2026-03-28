---
Date Created: "0318"
Status: "#idea"
topics: "[[Algorithms and Complexity]]"
tags:
  - "#Sorting_algorithms"
---
# Merge Sort
A divide and conquer sorting algorithm wherein you divide the elements by recursively cutting the array in half, and sort those subarrays, until you sort the array fully

Formula for the middle:
$$
middle=left + \frac{(right-left)}{2}
$$
or (to let the right side hold the most elements if size is odd)
$$
middle=\frac{(left + right)}{2}
$$
Why not `right / 2`?
- dividing the right with 2 would just get the half of the entire array and not the half of the divided sub-array
- Which would lead to the middle being outside of the range of the sub-array
- So using the formula will get the middle of the range of the sub-array because the left with shift the right side into the correct position
# Process
1. Cut the array in half, get the middle by `left + (right - left) / 2` 
2. Call the `merge_sort` function with the parameters set for the left side `left, middle`
3. Repeat steps 1 and 2 using recursion until theres one element left or if not `left < middle(right)`
4. Cut the array in half, get the middle by `left + (right - left) / 2` 
5. Call the `merge_sort` function with the parameters set for the right side `middle + 1, right`
6. Repeat steps 4 and 5 using recursion until theres one element left or if not `left < middle(right)`
7. Use the `merge` function to sort the subarray using the left and right sides (the merging process is similar to a ladder comparison kind of way)
8. Repeat all steps until array is sorted
# Implementation
```
void MERGE(int arr[], int l, int m, int r){
    int i ,j, k;
    int s1 = m - l + 1; // from left to middle
    int s2 = r - m; // from middle to right

    int L1[s1], L2[s2];

    for(int i = 0; i < s1; i++){
        L1[i] = arr[l + i];
    }

    for(int j = 0; j < s2; j++){
        L2[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    // Merge elements

    while(i < s1 && j < s2){

        if(L1[i] < L2[j]){
            arr[k] = L1[i];
            i++;
        }else{
            arr[k] = L2[i];
            j++;
        }
        k++;
    }

    while(i < s1){
        arr[k] = L1[i];
        i++;
        k++;
    }

    while(j < s2){
        arr[k] = L2[j];
        j++;
        k++;
    }

}

void MERGE_SORT(int arr[], int left, int right){
    
    if ( left < right){
        int middle = left + (right - left) / 2;
        MERGE_SORT(arr, left, middle);
        MERGE_SORT(arr, middle + 1, right);

        MERGE(arr, left, middle, right);
    }
}
```

# Stability: Stable
Stable because it always takes the left value first when there's an identical element meaning the relative order does not change
# In-place: No
The original merge sort is not in place since it creates arrays to store the left and right side. But it can be in-place with the iterative bottom-up approach in linked list implementation which is more complex than the original and more worse since it uses more memory

[[Stable Sorting Algorithms]]
[[In-place and Out-place sorting algorithms]]

---
# References