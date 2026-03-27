#ifndef RADIXSORT_H
#define RADIXSORT_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void RadixCountingSort(int arr[], int len, int exp){
    
    int* freqArr = (int*)calloc(10,sizeof(int));
    int* output = (int*)malloc(sizeof(int) * len);

    for(int i = 0; i < len; i++){
        freqArr[(arr[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++){
        freqArr[i] += freqArr[i - 1];
    }

    for(int i = len - 1; i >= 0; i--){
        int digit = (arr[i] / exp) % 10;
        output[freqArr[digit] - 1] = arr[i];
        freqArr[digit]--;
    }

    for(int i =0; i < len; i++){
        arr[i] = output[i];
    }

}

void RadixSort(int arr[], int len){

    int max = arr[0];

    for(int i = 0; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    for(int i = 1; max / i > 0; i *= 10){
        RadixCountingSort(arr, len, i);
    }

}




#endif