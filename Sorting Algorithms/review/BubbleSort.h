#ifndef BUBBLE_H
#define BUBBLE_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>

void BubbleSort(int arr[], int len){

    bool swapped = true;
    for(int i = 0; i < len - 1 && swapped; i++){
        bool swapped = false;
        for(int j = i + 1; j < len; j++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                swapped = true;
            }
        }
    }

}


#endif