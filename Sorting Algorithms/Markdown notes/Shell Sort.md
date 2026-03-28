---
Date Created: "20260313"
Status: "#idea"
topics: "[[Algorithms and Complexity]]"
tags:
  - "#Sorting_algorithms"
---
# Shell Sort
A comparison sorting algorithm that Works like insertion sort but sorts the elements gaps apart until that `gap < 1`
- Once `gap = 1` do standard insertion sort
## Process
1. Choose a gap sequence and start with that gap sequence
2. Get the length of your array and get the gap from it with the chosen gap sequence
3. Start by getting your key index as the gap 
4. compare elements that are gap apart, shift the gap apart element if that element is greater than the key
	- If element < key or element position < gap, insert the key at element + gap
5. Repeat steps 3 - 4 until gap == 1
6. Do Standard Insertion Sort

# Code
```
void shellSort(int arr[], int len){
    
    // start with getting the gap
    int gap = len / 2;
    while(gap > 0){
        printf("%d\n ", gap);
        // start the index at the gap position and increment till it reaches the end
        for(int i = gap; i < len; i++){
            //insertion sort
            int key = arr[i];
            int j = i;
            while(j >= gap && arr[j - gap] > key){
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
            display(arr, len);
        }
        // decrease the gap
        gap /= 2;
    }
}
```
# Stability: Unstable
Since shell sort shifts elements that are gaps apart, there is a chance where identical elements will lose relative order since identical elements can jump across each other during the sorting pr

[[Unstable Sorting Algorithm]]



---
# References

