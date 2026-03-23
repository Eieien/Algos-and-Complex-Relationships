#ifndef STRAND_H
#define STRAND_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define SENTINAL 999

void mergeStrand(int strand[], int strandSize, int result[], int resultSize){
    printf("MERGING\n");

    int output[strandSize + resultSize];
    
    int i =0 , j = 0, k = 0;

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
    printf("MERGED\n");


}

void StrandSort(int arr[], int len){

    int result[len];
    int resultSize = 0;
    int next = -1;
    int n = len;
    
    while(n > 0){
        int strand[len];
        int strandSize = 0;
        int val = -1;

        for(int i = 0; i < len; i++){

            if(arr[i] != SENTINAL && arr[i] >= val){
                strand[strandSize++] = arr[i];
                val = arr[i];
                arr[i] = SENTINAL;
                n--;
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