#ifndef COMBSORT_H
#define COMBSORT_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void CombSort(int arr[], int len){

    int gap = len / 1.3;
    bool swapped = true;
    while(gap > 0 && swapped){

        if(gap < 1)gap =1;
        swapped = false;
        for(int i = gap; i < len; i++){
            
            if(arr[i - gap] > arr[i]){
                int temp = arr[i];
                arr[i] = arr[i - gap];
                arr[i - gap] = temp;
                swapped = true;
            }
            
        }


        gap /= 1.3;

    }

}

#endif