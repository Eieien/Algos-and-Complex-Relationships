#ifndef SORTALGO_H
#define SORTALGO_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include "DictionaryBucketSort.h"
#include "ArrayBucketSort.h"

void display(int arr[], int len){

    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int len){
    printf("SELECTION SORT: \n");

    for(int i = 0; i < len - 1; i++){
        int min = i;
        for(int j = i + 1; j < len; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        
        if(arr[min] < arr[i]){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }else{
            break;
        }

    }
}

void bubbleSort(int arr[], int len){
    printf("BUBBLE SORT: \n");
    for(int i = 0; i < len - 1; i++){
        
        bool swapped = false;
        for(int j = 0; j < len - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if(!swapped){
            break;
        }
    }
}

void insertionSort(int arr[], int len){

    for(int i = 1; i < len; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
        
    }

}

void merge(int arr[], int l, int m, int r){

    int s1 = m - l + 1;
    int s2 = r - m;

    int L[s1], R[s2];

    for(int i = 0; i < s1; i++) L[i] = arr[l + i];
    for(int i = 0; i < s2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while(i < s1 && j < s2){

        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < s1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < s2){
        arr[k] = R[j];
        j++;
        k++;
    }


}

void merge_sort(int arr[], int l, int r){

    if(l < r){
        int m = (l +r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
}

//w3 schools version
void countingSort1(int arr[], int len){
    
    int max = arr[0];

    for (int i = 0; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int* countArr = calloc(max + 1, sizeof(int));

    for(int i = 0; i < len; i++){
        countArr[arr[i]]++;
    }

    int pos = 0;
    for(int i = 0; i < max + 1; i++){
        while(countArr[i] != 0){
            arr[pos] = i;
            countArr[i]--;
            pos++;
        }
    }
    free(countArr);
}

//geeksforgeeks version
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

void DictionaryBucketSort(int arr[], int len){
    int amount = (int)sqrt(len);
    LIST* buckets = createBuckets(amount);
    int min = arr[0];
    int max = arr[0];
    // find the minimum and maximum
    for(int i = 0; i < len; i++){
        if(min > arr[i]){
            min = arr[i];
        }

        if(max < arr[i]){
            max = arr[i];
        }
    }
    int range = getRange(min, max, amount);
    printf("%d \n", range);

    for(int i = 0; i < len; i++){
        int key = hash(arr[i], min, range);
        insertSorted(buckets, key, arr[i]);        
    }

    displayBuckets(buckets, amount);

    int k = 0;
    for(int i = 0; i < amount; i++){

        for(Node* curr = &buckets[i]; *curr != NULL;){
            arr[k] = (*curr)->val;
            k++;
            Node temp = *curr;
            curr = &(*curr)->link;
            free(temp);
        }
    }
    freeBuckets(buckets);
}

void ArrayBucketSort(int arr[], int len){
    int numBuckets = (int)sqrt(len);
    
    int min = arr[0], max = arr[0];

    for(int i = 0; i < len; i++){
        if(min > arr[i]){
            min = arr[i];
        }

        if(max < arr[i]){
            max = arr[i];
        }
    }
    
    int range = getRange(min, max, numBuckets);

    int** buckets = createArrayBuckets(numBuckets, range);

    for(int i = 0; i < len; i++){
        int key = hash(arr[i], min, range);
        insertIntoBucket(buckets, arr[i], key, range);        
    }

    sortBuckets(buckets, numBuckets, range);
    displayArrayBuckets(buckets, numBuckets, range);

    int i = 0;
    for(int j = 0; j < numBuckets; j++){

        for(int k = 0; k < range && buckets[j][k] < SENTINAL; k++){
            arr[i] = buckets[j][k];
            i++;
        }
    }
    
    freeArrayBuckets(buckets, numBuckets);
}


void shellSort(int arr[], int len){
    
    int gap = len / 2;

    while(gap >= 1){
        for(int i = gap; i < len; i++){
            int key = arr[i];
            int j = i;

            while( j >= gap && arr[j - gap] > key){
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
            display(arr, len);

        }

        gap /= 2;
    }
}

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

int HPartition(int arr[], int l, int r){

    int pivot = arr[l];
    int i = l, j = r;

    while(i < j){

        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;

    }

    return j;


}

int LPartition(int arr[], int l, int r){
    int pivot = r;

    int j = l;
    int i = j - 1;

    while(j < pivot){
        
        if(arr[j] <= arr[pivot]){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[pivot];
    arr[pivot] = temp;

    return i + 1;
}

void QuickSort(int arr[], int l, int r){

    if(l < r){
        // int p = HPartition(arr, l, r);
        int p = LPartition(arr, l, r);

        // QuickSort(arr, l, p);
        QuickSort(arr, l, p - 1);
        QuickSort(arr, p + 1, r);
    }
}
#endif