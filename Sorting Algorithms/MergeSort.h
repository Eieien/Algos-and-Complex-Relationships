#ifndef MERGESORT_H
#define MERGESORT_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

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
        // printf("%d %d %d\n",left, middle, right);
        MERGE_SORT(arr, left, middle);
        MERGE_SORT(arr, middle + 1, right);

        // printf("MERGING");
        MERGE(arr, left, middle, right);
    }
}

#endif