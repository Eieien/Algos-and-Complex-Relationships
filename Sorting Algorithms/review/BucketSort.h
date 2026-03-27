#ifndef BUCKET_H
#define BUCKET_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>

int getBucketRange(int numBuckets, int max, int min){
    return ((max - min) / numBuckets)  + 1;
}

int hash(int range, int min, int val){
    return ((val - min) / range);
}

void displayBuckets(int** buckets, int numBuckets, int len){

    for(int i = 0; i < numBuckets; i++){
        printf("%d: ", i);
        for(int j = 0; j < len && buckets[i][j] != INT_MAX; j++){
            printf("%d ", buckets[i][j]);
        }
        printf("\n");
    }
}


int** createBuckets(int numBuckets, int len){

    int** buckets = (int**)malloc(sizeof(int*) * numBuckets);

    for(int i = 0; i < numBuckets; i++){
        buckets[i] = (int*)malloc(sizeof(int) * len);
    }

    for(int i = 0; i < numBuckets; i++){
        for(int j = 0; j < len; j++){
            buckets[i][j] = INT_MAX;
        }
    }

    return buckets;

} 

void insertionSortBucket(int* bucket, int len){

    for(int i = 1; i < len && bucket[i] != INT_MAX; i++){
        int j = i - 1;
        int key = bucket[i];

        while(j >= 0 && bucket[j] > key){
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;

    }

}

void insertItem(int* bucket, int len, int val){
    int i;
    for(i = 0; i < len && bucket[i] != INT_MAX; i++){}
    if(i < len){
        bucket[i] = val;
    }

}

void BucketSort(int arr[], int len){
    int numBuckets = len;
    int** buckets = createBuckets(numBuckets, len);

    int min = arr[0], max = arr[0];

    for(int i = 0; i < len; i++){
        if(max < arr[i]){
            max = arr[i];
        }

        if(min > arr[i]){
            min = arr[i];
        }
    }

    int range = getBucketRange(numBuckets, max, min);
    
    for(int i = 0; i < len; i++){
        int key = hash(range, min, arr[i]);
        insertItem(buckets[key], len, arr[i]);
    }


    for(int i = 0; i < numBuckets; i++){
        insertionSortBucket(buckets[i], len);
    }
    // displayBuckets(buckets, numBuckets, len);
    int k = 0;
    for(int i = 0; i < numBuckets; i++){
        for(int j = 0; j < len && buckets[i][j] != INT_MAX; j++){
            arr[k++] = buckets[i][j];
        }
    }

}


#endif