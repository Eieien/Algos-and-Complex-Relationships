---
Date Created: "0320"
Status: "#idea"
topics: "[[Algorithms and Complexity]]"
tags:
  - Sorting_algorithms
---
# Quick Sort
A divide and conquer sorting Algorithm that recursively partitions the array by rearranging them within the partition.
## Pivot Selection
There are multiple pivot selection online and it depends on what you chose
# Partitioning
Rearranges elements within a specific condition, like moving smaller elements than the pivot to the left, and larger elements than the pivot to the right

Handles the sorting part in Quick Sort by rearranging elements within the partition 
# In-place: True
Unlike merge sort, where you create new arrays to sort both the left and right subarray and place it back to the original array. Quick sort only rearranges the array within the partitions
# Stability: Unstable
It is unstable because identical elements jump across each other when a swap is happening between the current element and a pivot element. 
It can be stable if you consider shifting the elements instead of directly swapping but it will require more time 
# Process
1. Pick a partition selection method (Hoare's, Lomuko, Dutch Flag or something smh)
2. Sort the array within the partition method by rearranging
3. Return a partition index from the partition selection method
4. Divide the array using the partition value
5. Repeat until the entire array is sorted

# Hoare's Partition
Uses two pointers where one pointer is at the start and the other is at the end,  and they move toward each other when they find elements that need to be swapped
When both points cross each other, the array is partitioned, with elements less than the pivot to the left and the elements greater than the pivot to the right, this repeats until the array is sorted
## Partitioning Process
1. Pick a pivot element using any pivot selection process
2. Create two pointers `i` and `j`, `i` starts at the beginning of the partition, `j` starts at the end of the partition
3. if `arr[i]` < `pivot`, increment `i` until `arr[i] >= pivot`
4. if `arr[j]` > `pivot`, increment `j` until `arr[j] <= pivot`  
5. Swap `arr[i]` and `arr[j]`
6. Return `j` as the middle index of the next partition
## Hoare's Partition Implementation (REVIEW)
```
int HoarePartition(int arr[], int left, int right){

    int pivot = arr[left];
    int i = left ;
    int j = right;
    
    while(i < j){
        
        while(arr[i] < pivot){
            i++;
        }
        
        while(arr[j] > pivot){
            j--;
        }
        
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    printf("%d %d %d \n", pivot, arr[i], arr[j]);

    return j;
}

void quickSort(int arr[], int left, int right){
    
    if(left < right){
        int partition = HoarePartition(arr, left, right);

        quickSort(arr, left, partition);
        quickSort(arr, partition + 1, right);
    }
    
}
```

# Lomuto Partition
Uses a two pointer approach where one pointer focuses on the swapping and the other for the traversal, as you traverse, smaller elements move to the left side of the boundary and the boundary expands. After traversing the array, elements to the left side of the boundary are smaller than the pivot, while the other side is bigger than the pivot
- Assumes the pivot position to be the last element
## Partitioning Process
1. Choose the last element as the pivot
2. Set `j` at the starting index of the partition and `i` at `i - 1` for swapping
3. if `arr[j] <= pivot`, increment `i` and swap `arr[j]` with `arr[i]`
4. Repeat step 3 until `j` reaches the end
5. All elements smaller than the pivot should be on the left side of `i`
6. Swap `arr[i]` with the `pivot` to place it in the correct position
7. The array should be arranged like this, `smaller` < `pivot` < `greater`
8. array is sorted

# Lomuto Partition Implementation
```
int LomutoPartition(int arr[], int left, int right){
    int pivot = right;
    int j = left;
    int i = j - 1;

    while(j < pivot){
        
        if(arr[j] <= arr[pivot]){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[pivot];
    arr[pivot] = temp;

    return i + 1; // pivot index
}

void quickSort(int arr[], int left, int right){
    
    if(left < right){
        // int partition = HoarePartition(arr, left, right);

        int partition = LomutoPartition(arr, left, right);
		// Since the pivot is already in the its correct position, we don't have to include it in the next pass, so we minus partition by 1 to get the left side only
        quickSort(arr, left, partition - 1);
        quickSort(arr, partition + 1, right);
    }
    
}
```

[[In-place and Out-place sorting algorithms]]
[[Unstable Sorting Algorithm]]

---
# References
https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/ 
https://www.geeksforgeeks.org/dsa/hoare-s-partition-algorithm/ 