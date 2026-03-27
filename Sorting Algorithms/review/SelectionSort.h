#ifndef SELECTION_H
#define SELECTION_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void SelectionSort(int arr[], int len){

    for(int i = 0; i < len; i++){
        int min = i;
        
        for(int j = i + 1; j < len; j++){
            
            if(arr[min] > arr[j]){
                min = j;
            }
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}


#endif
