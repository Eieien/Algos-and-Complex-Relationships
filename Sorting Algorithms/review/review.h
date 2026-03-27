#ifndef REVIEW_H
#define REVIEW_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void display(int arr[], int len){

    printf("\n");
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
}



int HoarePartitioning(int arr[], int l, int r){

    int i = l;
    int j = r;
    int pivot = arr[l];
    while(i < j){

        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;

        }
    }
    return j;

}



#endif