#include<stdio.h>
#include<stdlib.h>
#include "SortingAlgos.h"

int main(){

    // int arr[5] = {64, 25, 12, 22, 11};
    // int arr[4] = {38, 27, 43, 10};
    int arr[8] = {2, 5, 3, 0, 2, 3, 0, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
   
    // selectionSort(arr, len);
    countingSort2(arr, len);
    printf("Final: ");
    display(arr, len);
    

    return 0;
}
