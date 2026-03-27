#ifndef QUICK_H
#define QUICK_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int LomutoPartition(int arr[], int l, int r){

        int pivot = r;
        int j = l, i = l -1;
    
        while(j < r){
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

int HoarePartition(int arr[], int l, int r){
    int pivot = arr[l];
    int j = r + 1;
    int i = l - 1;

    while(1){

        do{
            i++;

        }while(arr[i] < pivot);

        do{

            j--;
        }while(arr[j] > pivot);

        if(i >= j){
            return j;
        }

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    return j;
}

void QuickSort(int arr[], int l, int r){

    if(l < r){
        // int partition = LomutoPartition(arr, l, r);
        int partition = HoarePartition(arr, l, r);
    
        QuickSort(arr, l, partition );
        // QuickSort(arr, l, partition - 1);
        QuickSort(arr, partition + 1, r);

    }

}



#endif