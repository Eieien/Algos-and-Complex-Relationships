#ifndef HEAP_H
#define HEAP_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>


int parent(int idx){
    return (idx - 1) / 2;
}

int leftChild(int idx){
    return (idx * 2) + 1; 
}

int rightChild(int idx){
    return idx * 2 + 2;
}

void MaxHeapify(int arr[], int i){

    
}

void MaxHeapSort(int arr[], int len){

}

void MinHeapSort(int arr[], int len){
    
}


#endif
