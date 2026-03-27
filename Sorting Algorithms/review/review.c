#include<stdio.h>
#include<stdlib.h>
#include "review.h"
#include "BucketSort.h"
#include "StrandSort.h"
#include "Tournament.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "CombSort.h"
#include "CountingSort.h"
#include "ShellSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "GnomeSort.h"
#include "QuickSort.h"

int main(){

    // int arr[5] = {64, 25, 12, 22, 11};
    // int arr[4] = {38, 27, 43, 10};
    // int arr[5] = {10, 80, 30, 90, 40};
    int arr[8] = {2, 5, 3, 0, 2, 3, 0, 3};
    // int arr[4] = {2, 2, 2, 1};
    // int arr[8] = {5, 3, 8, 4, 2, 7, 1, 10};
    // int arr[8] = {29, 25, 3, 49, 9, 37, 21, 43};
    // int arr[9] = {22, 11, 25, 12, 45, 34, 90, 88, 64};
    int len = sizeof(arr) /sizeof(arr[0]);
    
    // insertionSort(arr, len);
    // GnomeSort(arr, len);
    // BucketSort(arr, len);
    // BubbleSort(arr, len);
    // StrandSort(arr, len);
    // InsertionSort(arr, len);
    // OfflineTournamentSort(arr, len);
    // ShellSort(arr, len);
    // MinHeapSort(arr, len);
    // SelectionSort(arr, len);
    // CountingSort(arr, len);
    // BubbleSort(arr, len);
    // CombSort(arr, len);
    // MergeSort(arr, 0, len - 1);
    // SelectionSort(arr, len);
    // RadixSort(arr, len);
    QuickSort(arr, 0, len - 1);
    display(arr,len);

    return 0;
}