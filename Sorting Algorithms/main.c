#include<stdio.h>
#include<stdlib.h>
#include "SortingAlgos.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "TournamentSort.h"
#include "StrandSort.h"

int main(){

    // int arr[5] = {64, 25, 12, 22, 11};
    // int arr[4] = {38, 27, 43, 10};
    // int arr[5] = {10, 80, 30, 90, 40};
    // int arr[8] = {2, 5, 3, 0, 2, 3, 0, 3};
    int arr[8] = {5, 3, 8, 4, 2, 7, 1, 10};
    // int arr[8] = {29, 25, 3, 49, 9, 37, 21, 43};
    // int arr[9] = {22, 11, 25, 12, 45, 34, 90, 88, 64};
    int len = sizeof(arr) / sizeof(arr[0]);
   
    // insertionSort(arr, len);
    // selectionSort(arr, len);
    // countingSort2(arr, len);
    // DictionaryBucketSort(arr, len);
    // ArrayBucketSort(arr, len);
    // GnomeSort(arr, len);
    // CombSort(arr, len);
    // MERGE_SORT(arr, 0, len - 1);
    // QuickSort(arr, 0, len -1);
    // RadixSort(arr, len);`1
    // OfflineTournamentSort(arr, len);
    OnlineTournamentSort(arr, len);
    // StrandSort(arr, len);
    printf("Final: ");
    display(arr, len);
    

    return 0;
}
