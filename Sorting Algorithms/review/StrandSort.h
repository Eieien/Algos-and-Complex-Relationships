#ifndef STRAND_H
#define STRAND_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>

#define SENTINAL 999

void displayStrand(int strand[], int strandSize){
    
    for(int i = 0; i < strandSize; i++){
        printf("%d ", strand[i]);
    }
    printf("\n");
}

void mergeStrand(int strand[], int strandSize, int result[], int resultSize){

    int output[strandSize + resultSize];
    
    int i = 0, j = 0, k = 0;

    while(i < strandSize && j < resultSize){
        if(strand[i] < result[j]){
            output[k++] = strand[i++];
        }else{
            output[k++] = result[j++];
        }
    }

    while(i < strandSize){
        output[k++] = strand[i++];
    }

    while(j < resultSize){
        output[k++] = result[j++];
    }

    for(int i = 0; i < k; i++){
        result[i] = output[i];
    }
    
}



void StrandSort(int arr[], int len){
    int strand[len];
    int strandSize = 0;
    int remaining = len;
    int result[len];
    int resultSize = 0;

    while(remaining > 0){

        int min = INT_MIN;
        strandSize = 0;
        for(int i = 0; i < len; i++){
            // instead of shifting the elements, replace them with sentinel value to mark it as placed in the strand
            if(arr[i] != INT_MAX && arr[i] > min){
                strand[strandSize++] = arr[i];
                min = strand[strandSize - 1];
                arr[i] = INT_MAX;
                remaining--;
            }

        }
        mergeStrand(strand, strandSize, result, resultSize);
        resultSize += strandSize;
    }
    for(int i = 0; i < len; i++){
        arr[i] = result[i];
    }

}


#endif