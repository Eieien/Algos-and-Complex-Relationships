#ifndef INSERTION_H
#define INSERTION_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void InsertionSort(int arr[], int len){

    for(int i = 0; i < len; i++){

        int j = i - 1;
        int key = arr[i];

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--; 
        }

        arr[j + 1] = key;
    }

}

#endif