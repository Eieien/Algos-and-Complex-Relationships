#ifndef MERGESORT_H
#define MERGESORT_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void MERGE(int arr[], int l, int m, int r){

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i = 0 ; i < n1; i++){
        L[i] = arr[l + i];
    }

    for(int i = 0; i < n2; i++){
        R[i] = arr[m + i + 1];
    }

    int i =0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }

    while(i < n1)arr[k++] = L[i++];

    while(j < n2)arr[k++] = R[j++];

}

void MergeSort(int arr[], int l, int r){

    if(l < r){

        int m = (l + r) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        MERGE(arr, l, m ,r);
    }

}

#endif