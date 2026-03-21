#ifndef ARRAYBUCKET_H
#define ARRAYBUCKET_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SENTINAL 99999999

void displayArrayBuckets(int** buckets, int numBuckets, int range){

    for(int i = 0; i < numBuckets; i++){
        printf("%d -> ", i);
        for(int j = 0; j < range && buckets[i][j] != SENTINAL; j++){
            printf("%d -> ", buckets[i][j]);
        }
        printf("\n");
    }
}

int** createArrayBuckets(int numBuckets, int range){

    int** buckets = (int**)malloc(sizeof(int*) * numBuckets);

    for(int i = 0; i < numBuckets; i++){
        buckets[i] = (int*)malloc(sizeof(int) * range);
    
        for(int j = 0; j < range; j++){
            buckets[i][j] = SENTINAL;
        }
    }
    // displayArrayBuckets(buckets, numBuckets, range);
    return buckets;
}

void freeArrayBuckets(int** buckets, int numBuckets){

    for(int i = 0; i < numBuckets; i++){
        
        free(buckets[i]);
    }

    free(buckets);
}

void insertIntoBucket(int** buckets, int val, int key, int range){
    int i;
    for(i = 0; i < range && buckets[key][i] < SENTINAL; i++){}

    if(i < range){
        buckets[key][i] = val;
    }
}

void sortBuckets(int** buckets, int numBuckets, int range){
    
    for(int i = 0; i < numBuckets; i++){
        for(int j = 0; j < range && buckets[i][j] < SENTINAL; j++){

            int key = buckets[i][j];
            int k = j - 1;

            while(k >= 0 && buckets[i][k] > key){
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }

            buckets[i][k + 1]= key;
        }
    }
}





#endif