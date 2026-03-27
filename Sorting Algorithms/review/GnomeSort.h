#ifndef GNOME_H
#define GNOME_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void GnomeSort(int arr[], int len){
    int i = 1;

    while(i < len){
        
        if(i >= 1 && arr[i - 1] > arr[i] ){
            int temp = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = temp;
            i--;
        }else{
            i++;
        }
    }
}

#endif