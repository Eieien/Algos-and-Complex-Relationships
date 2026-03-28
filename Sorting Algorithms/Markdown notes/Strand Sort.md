---
Date Created: "0323"
Status: "#idea"
topics: "[[Algorithms and Complexity]]"
tags:
  - "#Sorting_algorithms"
---
# Strand Sort
Uses 2 arrays `strand` and `result` to store values. Works by getting the first element of the original array, and placing it into the strand and getting the elements that is greater than the strand from the original array

# Process
1. Create two arrays `strand` to store the current order values, and `result` to store the initial sorted arrays from the current result and current strand

# Implementation

```
void mergeResult(int strand[], int strandSize, int result[], int resultSize){

    int R[resultSize + strandSize];
    int k = 0;
    int i =0, j = 0;

    while(i < resultSize && j < strandSize){
        if(strand[j] < result[i]){
            R[k] = strand[j];
            k++;
            j++;
        }else{
            R[k] = result[i];
            k++;
            i++;
        }
    }

    while(i < resultSize){
        R[k++] = result[i];
        i++;
    }

    while(j < strandSize){
        R[k++] = strand[j];
        j++;
    }

    for(int i = 0; i < k; i++){
        result[i] = R[i];
    }

}

void StrandSort(int arr[], int len){

    int strand[100];
    int strandSize = 0;
    int result[len];
    int resultSize= 0;
    int temp[100];
    int n = len;
    int tempSize = 0;
    
    while(n > 0){
        // Get the first element
        tempSize = 0;
        strandSize = 0;
        strand[strandSize++] = arr[0];
        printf("First Strand: %d \n", strand[0]);
        for(int i = 1; i < n; i++){
            if(strand[strandSize - 1] < arr[i]){
                strand[strandSize++] = arr[i];
            }else{
                temp[tempSize++] = arr[i]; 
            }
        }
        
        mergeResult(strand, strandSize, result, resultSize);
        resultSize += strandSize;
        n = tempSize;
        for(int i =0; i < n; i++){
            arr[i] = temp[i];
        }
        displayStrandArray(strand, strandSize);
        displayStrandArray(result, resultSize);
        displayStrandArray(arr, n);
        printf("\n");
    }

    for(int i =0 ; i < len; i++){
        arr[i] = result[i]; 
    }
}
```



---
# References