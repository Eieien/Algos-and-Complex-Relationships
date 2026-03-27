#ifndef SHELL_H
#define SHELL_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void ShellSort(int arr[], int len){

    int gap = len / 2;

    while(gap > 0){

        for(int i = gap; i < len; i++){

            int j = i;
            int key = arr[i];

            while(j >= gap && arr[j - gap] > key){
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = key;

        }


        gap /= 2;
    }
}


#endif