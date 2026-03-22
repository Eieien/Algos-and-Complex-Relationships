#ifndef RADIX_H
#define RADIX_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void countingRadixSort(int arr[], int len, int exp){

    int output[len];
    int count[10] = {0};

    for(int i = 0; i < len; i++){
        count[(arr[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1]; 
    }

    for(int i = len - 1; i >= 0; i--){
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i < len; i++){
        arr[i] = output[i];
    }

}

void RadixSort(int arr[], int len){
    
    int max = arr[0];
    for(int i = 0; i < len; i++){
        if(max < arr[i]) max = arr[i];
    }
    
    for(int exp = 1; max / exp > 0; exp *= 10){
        countingRadixSort(arr, len, exp);
    }

}

#endif