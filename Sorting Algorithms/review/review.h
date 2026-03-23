#ifndef REVIEW_H
#define REVIEW_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void display(int arr[], int len){

    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
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

void ShellSort(int arr[], int len){

    int gap = len / 2;

    while(gap >= 1){
        
        for(int i = gap; i < len; i++){

            int j = i;
            int key = arr[i];
            while(j >= gap && arr[j - gap] > key){
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = key;
        }
        gap /= 2;
    }

}

void SelectionSort(int arr[], int len){

    for(int i = 0; i < len - 1; i++){

        int min = i;
        
        for(int j = i + 1; j < len; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        if(arr[min] < arr[i]){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

}

void CountingSort(int arr[], int len){
    
    int max = arr[0];

    for(int i =0 ; i < len; i++){
        if(max < arr[i]) max= arr[i];
    }

    int* freq = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(sizeof(int) * len);

    for(int i = 0; i < len; i++){
        freq[arr[i]]++;
    }
    
    // Prefix sum;
    for(int i = 1; i <= max; i++){
        freq[i] += freq[i - 1];
    }


    //Inserting Process
    for(int i = len -1; i >= 0; i--){
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    for(int i = 0; i < len; i++){
        arr[i] = output[i];
    }
    free(freq);
    free(output);
}

void GnomeSort(int arr[], int len){

    int i = 1;
    while(i < len){
        if(arr[i] < arr[i - 1] && i > 0){
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }else{
            i++;
        }
    }
}

void BubbleSort(int arr[], int len){

    for(int i = 0; i < len - 1; i++){

        for(int j = i; j < len; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
        }
    }

}

void CombSort(int arr[], int len){

    int gap = len / 1.3;

    while(gap >= 1){

        if(gap < 1) gap = 1;

        for(int i = gap; i < len; i++){
            
            int j = i - gap;

            if(arr[j] > arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        gap /= 1.3;
    }

}

void Merge(int arr[], int l, int m, int r){

    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++){
        L[i] = arr[l + i];    
    }

    for(int i = 0; i < n2; i++){
        R[i] = arr[m + i + 1];
    }

    int i = 0, j = 0, k = l;
    
    while(i < n1 && j < n2){
        
        if(L[i] < R[j]){
            arr[k++] = L[i++]; 
        }else{
            arr[k++] = R[j++];
        }
    }

    while(i < n1){
        arr[k++] = L[i++];
    }

    while(j < n2){
        arr[k++] = R[j++];
    }

}

void MergeSort(int arr[], int l, int r){

    if(l < r){

        int m = (l + r) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}

int HoarePartitioning(int arr[], int l, int r){

    int i = l;
    int j = r;
    int pivot = arr[l];
    while(i < j){

        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;

        }
    }
    return j;

}

int LomutoPartitioning(int arr[], int l, int r){

    int j = l;
    int i = l -1;
    int pivot = r;
    
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

    return i + 1;

}

void QuickSort(int arr[], int l, int r){

    if(l < r){

        int p = HoarePartitioning(arr, l, r);
        QuickSort(arr, l, p);

        QuickSort(arr, p + 1, r);
    }
}


#endif