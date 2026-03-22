#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SENTINAL 99999999

void TournamentSort(int arr[], int len);

void initTree(int tree[], int len){

    for(int i = 0; i < len; i++){
        tree[i] = SENTINAL;
    }
}

int parent(int idx){
    return (idx - 1) / 2;
}

int leftChildIdx(int parentIdx){
    return (2 * parentIdx) + 1;
}

int RightChildIdx(int parentIdx){
    return (2 * parentIdx) + 2;
}

int Min(int leftVal, int rightVal){
    return (leftVal < rightVal) ? leftVal : rightVal; 
}

void displayTree(int tree[], int len){

    printf("TREE: ");
    for(int i = 0; i < len; i++){
        printf("%d ", tree[i] == SENTINAL ? 99 : tree[i]);
    }
    printf("\n");
}

void Match(int tree[], int offset){
    for(int i = offset - 1; i >= 0; i--){
        tree[i] = Min(tree[leftChildIdx(i)], tree[RightChildIdx(i)]);
    }
}

void UpdateTree(int tree[], int val, int treeSize){
    int i;
    for(i = 0; leftChildIdx(i) < treeSize; ){
        if(tree[leftChildIdx(i)] == val){
            i = leftChildIdx(i);
        }

        if(tree[RightChildIdx(i)] == val){
            i = RightChildIdx(i);
        }
    }

    tree[i] = SENTINAL;
}

void OfflineTournamentSort(int arr[], int len){

    int treeSize = 2 * len - 1;
    int tree[treeSize];
    initTree(tree,treeSize);
    int offset = len - 1;

    for(int i = 0; i < len; i++){
        tree[offset + i] = arr[i];
    }
    
    for(int i = 0; i < len; i++){
        Match(tree, offset);
        arr[i] = tree[0];
        UpdateTree(tree, arr[i], treeSize);
    }


    displayTree(tree, treeSize);
}



#endif