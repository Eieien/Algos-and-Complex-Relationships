#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>

int parent(int idx){
    return (idx - 1) / 2;
}

int leftChild(int idx){
    return (idx * 2) + 1;
}

int rightChild(int idx){
    return (idx * 2) + 2;
}

int MIN(int L, int R){
    return (L < R) ? L : R;
}

void displayTree(int tree[], int treeSize){
    printf("Tree: ");
    for(int i = 0 ; i < treeSize; i++){
        printf("%d ", tree[i]);
    }

    printf("\n");
}

int winner(int tree[], int treeSize, int offset){
    
    int i;
    for(i = offset - 1; i >= 0; i--){
        tree[i] =(tree[leftChild(i)] < tree[rightChild(i)]) ? tree[leftChild(i)] : tree[rightChild(i)];
    }

    int winner = tree[0];

    i = 0;
    
    while(leftChild(i) < treeSize){
        i = (tree[leftChild(i)] == winner) ? leftChild(i) : rightChild(i);
    }

    tree[i] = INT_MAX;

    return winner;

}


void OfflineTournamentSort(int arr[], int len){

    int treeSize = len * 2 - 1;
    int tree[treeSize];
    int offset = len - 1;

    for(int i = 0 ; i < len; i++){
        tree[offset + i] = arr[i];
    }    

    for(int i = 0 ; i < len; i++){
        arr[i] = winner(tree, treeSize, offset);
    }


}

#endif