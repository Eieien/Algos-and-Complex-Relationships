#ifndef SORTALGO_H
#define SORTALGO_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Dicitionary.h"

void display(int arr[], int len){

    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int len){
    printf("SELECTION SORT: \n");

    for(int i = 0; i < len - 1; i++){
        int min = i;
        for(int j = i + 1; j < len; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        
        if(arr[min] < arr[i]){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }else{
            break;
        }

    }
}

void bubbleSort(int arr[], int len){
    printf("BUBBLE SORT: \n");
    for(int i = 0; i < len - 1; i++){
        
        bool swapped = false;
        for(int j = 0; j < len - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if(!swapped){
            break;
        }
    }
}

void insertionSort(int arr[], int len){

    for(int i = 1; i < len; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
        
    }

}

void mergeSort(int arr[], int len){
    printf("MERGE SORT: \n");
    
    
}
//w3 schools version
void countingSort1(int arr[], int len){
    
    int max = arr[0];

    for (int i = 0; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int* countArr = calloc(max + 1, sizeof(int));

    for(int i = 0; i < len; i++){
        countArr[arr[i]]++;
    }

    int pos = 0;
    for(int i = 0; i < max + 1; i++){
        while(countArr[i] != 0){
            arr[pos] = i;
            countArr[i]--;
            pos++;
        }
    }
    free(countArr);
}

//geeksforgeeks version
void countingSort2(int arr[], int len){

    int max = arr[0];

    for(int i = 0; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int* countArr = calloc(max + 1, sizeof(int));

    for(int i = 0; i < len; i++){
        countArr[arr[i]]++;
    }

    for(int i = 1; i < max + 1; i++){
        countArr[i] = countArr[i - 1] + countArr[i];
    }
    printf("Cumulative Sum: ");
    display(countArr, max + 1);

    int* ans = malloc((len) * sizeof(int));
    
    for(int i = len - 1; i >= 0; i--){
        ans[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
        // printf("%d %d %d ", i, arr[i] ,countArr[arr[i] - 1]);
    }

    for(int i = 0; i < len; i++){
        arr[i] = ans[i];
    }

    free(countArr);
    free(ans);
}

// Using linked list to represent buckets
void bucketSort(int arr[], int len){
    
    Dictionary D;

    initDict(D);

    for(int i = 0; i < len; i++){
        insertSorted(D, arr[i]);       
    }

    int pos = 0;
    for(int i = 0; i < len; i++){
        // fix deleteion of nodes here
        for(Node curr = D[i]; curr != NULL; ){
            Node temp = curr;
            arr[pos] = curr->val;
            pos++;
            curr = curr->link;
            free(temp);
        }
    }
    initDict(D);
    displayDict(D);
}

void shellSort(int arr[], int len){
    
    int n = 2;
    for(int gap = len / n; gap >= 1; gap = len / n){

        int end = gap;
        for(int i = 0; end < len; end++, i++){
            int key = arr[end];
            int j = i;

            while(j >= 0 && arr[j] > key){
                arr[j + gap] = arr[j];
                j = (gap == 1) ? j - 1 : gap - j;
                printf("%d\n", j);
            }

            arr[j] = key;
        }
        // for(int i = 0; gap < len; gap++, i++){

        //     int key = arr[gap];
        //     int j = i;

        //     while(j >= 0 && arr[j] > key){
        //         arr[j + gap] = arr[j];
        //         j = gap - j;
        //         printf("%d\n", gap);
        //     }

        //     arr[j + gap] = key;

        // }


        n *= 2;
    }
}

#endif