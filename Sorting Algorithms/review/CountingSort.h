#ifndef COUNTING_H
#define COUNTING_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void CountingSort(int arr[], int len){

    int min = arr[0], max = arr[0];
    for(int i = 0; i < len; i++){
        if(max < arr[i]){
            max = arr[i];
        }
        if(min > arr[i]){
            min = arr[i];
        }
    }

    int range = max - min + 1;

    int* freqArr = (int*)calloc(range,sizeof(int));
    int* output = (int*)malloc(len * sizeof(int));

    for(int i = 0; i < len; i++){
        freqArr[arr[i] - min]++;
    }

    for(int i = 1; i < range; i++){
        freqArr[i] += freqArr[i - 1];
    }

    for(int i = len - 1; i >= 0; i--){
        output[freqArr[arr[i] - min] - 1] = arr[i];
        freqArr[arr[i]-min]--;
    }

    for(int i = 0; i < len; i++){
        arr[i] = output[i];
    }


}


#endif