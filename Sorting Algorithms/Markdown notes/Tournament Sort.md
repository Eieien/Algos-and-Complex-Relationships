---
Date Created: "0322"
Status: "#idea"
topics: "[[Algorithms and Complexity]]"
tags:
  - "#Sorting_algorithms"
---
# Tournament Sort
A heapsort variant that starts from the bottom and goes up. Works by having values at the bottom of tree as competitors, and the parent indexes of those competitors will be the winner of those competitors. 
# Key Terms
Competitors -> Elements that will be compared against each other
Winner -> Minimum or maximum value of the competitors
Champion -> The smallest or largest value of the current tournament that is placed back into the original array

# Offline Tournament Sort 
# Process
1. Create a an `tree` Array with size `2 * len - 1`
2. Initialize the `tree` with all values set to `INF` or sentinel values
3. Create an `offset` variable with a value of `len - 1`
4. Copy the elements of the unsorted array to the `tree` Array starting from `offset`. This will be the placement of the competitors
5. **(Matches Part)** For each parent of the competitors, find the minimum or maximum value of both children and place that value on the parent. After doing that the parent will become competitors against their sibling 
6. Repeat until a winner is found at the root element of the tree
7. Place the winner element into the original array with the correct position
8. Trace back the root's leaf position and set it to the sentinel value, meaning it no longer competes
9. Repeat Step 5 - 8 until the array is sorted
## Implementation
### Priority Queue Functions
Required to find the parent and it's children
```
int parent(int idx){
    return (idx - 1) / 2;
}

int leftChildIdx(int parentIdx){
    return (2 * parentIdx) + 1;
}

int RightChildIdx(int parentIdx){
    return (2 * parentIdx) + 2;
}
// Needed to get the minimum between two values
int Min(int leftVal, int rightVal){
    return (leftVal < rightVal) ? leftVal : rightVal; 
}
```
### Initialize the tree
```
void initTree(int tree[], int len){

    for(int i = 0; i < len; i++){
        tree[i] = SENTINAL;
    }
}
```
### Displaying the tree
```
void displayTree(int tree[], int len){

    printf("TREE: ");
    for(int i = 0; i < len; i++){
        printf("%d ", tree[i] == SENTINAL ? 99 : tree[i]);
    }
    printf("\n");
}
```
### Match
Where elements compete to see who's the root node
```
void Match(int tree[], int offset){
    for(int i = offset - 1; i >= 0; i--){
        tree[i] = Min(tree[leftChildIdx(i)], tree[RightChildIdx(i)]);
    }
}
```
### Update Tree (needs tweaking)
Update the tree to replace the winner's origin with the sentinel value to specify that it's done with the tournament
```
void UpdateTree(int tree[], int val, int treeSize){
    int i;
    for(i = 0; leftChildIdx(i) < treeSize; ){
        if(tree[leftChildIdx(i)] == val){
            i = leftChildIdx(i);
        }

        if(tree[RightChildIdx(i)] == val){
            i = RightChildIdx(i);
        }
    }

    tree[i] = SENTINAL;
}
```
### Actual Sort
```
void TournamentSort(int arr[], int len){

    int treeSize = 2 * len - 1;
    int tree[treeSize];
    initTree(tree,treeSize);
    int offset = len - 1;

    for(int i = 0; i < len; i++){
        tree[offset + i] = arr[i];
    }
    
    for(int i = 0; i < len; i++){
        Match(tree, offset);
        arr[i] = tree[0];
        UpdateTree(tree, arr[i], treeSize);
    }

    displayTree(tree, treeSize);
}
```

# Stability: Stable
If both identical elements are competing, the left side will always be chosen meaning the relative order will be the same

# In-place: False
Requires a priority queue to handle the sorting

[[Stable Sorting Algorithms]]
[[In-place and Out-place sorting algorithms]]

---
# References