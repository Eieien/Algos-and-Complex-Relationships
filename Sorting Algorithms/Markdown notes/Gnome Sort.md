---
Date Created: "20260314"
Status: "#idea"
topics: "[[Algorithms and Complexity]]"
tags:
  - "#Sorting_algorithms"
---
# Gnome Sort
A comparison based sorting algorithm
- Works by going back and fourth similar as a garden gnome's role
- Also known as stupid sort
- Only for educational purposes
# Process
1. Start trav element at index 1
2. Compare the element behind
	- If the element behind < current element
		- Traverse index forward
	- Otherwise
		- Swap, traverse backward if current index > 0
3. Repeat step 2 until the traversal reaches the end

# Stability: Stable
- Only checks if the previous value is greater than the current. So it maintains relative order when it compares identical values

# Implementation
```
void GnomeSort(int arr[], int len){
    int curr = 1;

    while(curr < len){
        // if curr < prev switch and move backward
        if(arr[curr] < arr[curr - 1] && curr > 0){
            
            int temp = arr[curr];
            arr[curr] = arr[curr - 1];
            arr[curr - 1] = temp;
            curr--;

        }else{
            curr++;
        }
    }
}
```

[[Stable Sorting Algorithms]]

---
# References