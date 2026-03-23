#ifndef BUCKET_H
#define BUCKET_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define SENTINAL 999

void displayBuckets(int** buckets, int numBuckets, int len){
    for(int i = 0; i < numBuckets; i++){
        printf("[%d]", i );

        for(int j = 0 ; j < len && buckets[i][j] != SENTINAL; j++){
            printf("%d ", buckets[i][j]);
        }
        printf("\n");
    }
}

int** InitializeBuckets(int len, int numBuckets){

    int** buckets = (int**)malloc(sizeof(int*) * numBuckets);

    for(int i = 0; i < numBuckets; i++){
        buckets[i] = (int*)malloc(sizeof(int) * len);
    }
    
    for(int i = 0; i < numBuckets; i++){
        for(int j = 0; j < len; j++){
            buckets[i][j] = SENTINAL;
        }
    }

    return buckets;
}

void insertBucket(int** buckets, int val, int key, int len){
    int i;
    for(i = 0; buckets[key][i] != SENTINAL && i < len ; i++){}
    buckets[key][i] = val;

}

int bucketRange(int max, int min, int numBuckets){
    return ((max - min) / numBuckets) + 1;
}

int bucketIdx(int num, int min, int bucketRange){
    return (num - min) / bucketRange;
}

void freeBuckets(int** buckets, int numBuckets){
    
    for(int i = 0; i < numBuckets; i++){
        free(buckets[i]);
    }

    free(buckets);
}

void SortBucket(int* bucket, int len){

    for(int i = 1; i < len; i++){
        
        int key = bucket[i];
        int j = i;

        while(j > 0 && bucket[j - 1] > key){
            bucket[j] = bucket[j - 1];
            j--;
        }
        bucket[j] = key;
    }

}

void BucketSort(int arr[], int len){

    int numBuckets = sqrt(len);
    int** buckets = InitializeBuckets(len, numBuckets);

    int min = arr[0], max = arr[0];
    
    for(int i = 0; i < len; i++){
        if(min > arr[i]){
            min = arr[i];
        }
        
        if(max < arr[i]){
            max = arr[i];
        }
    }
    int range = bucketRange(max, min, numBuckets);

    for(int i = 0; i < len; i++){
        int key = bucketIdx(arr[i], min, range);
        insertBucket(buckets, arr[i], key, len);
    }
    displayBuckets(buckets, numBuckets, len);

    for(int i = 0; i < numBuckets; i++){
        SortBucket(buckets[i], len);
    }

    int k = 0;
    for(int i = 0; i < numBuckets; i++){
        for(int j = 0; j < len && buckets[i][j] != SENTINAL; j++){
            arr[k++] = buckets[i][j];
        }
    }

    displayBuckets(buckets, numBuckets, len);
    freeBuckets(buckets, numBuckets);
    
}

#endif