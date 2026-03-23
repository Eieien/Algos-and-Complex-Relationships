#include<stdio.h>
#include<stdlib.h>
#define MAX 11

typedef struct{

    int last;
    int arr[MAX];

}HEAP;

int parentIdx(int childIdx){
    return (childIdx - 1) / 2;
}

int leftChildIdx(int parentIdx){
    return (2 * parentIdx) + 1;
}

int RightChildIdx(int parentIdx){
    return (2 * parentIdx) + 2;
}

void initPOT(HEAP* H){
    H->last = 0;
}

void heapify(HEAP* H){
    for(int i = H->last; H->arr[parentIdx(i)] < H->arr[i]; i = parentIdx(i)){
        int temp = H->arr[i];
        H->arr[i] = H->arr[parentIdx(i)];
        H->arr[parentIdx(i)] = temp;
    }
}

void insert(HEAP* H, int val){
    
    H->arr[H->last] = val;
    heapify(H);
    
    H->last++;
}


void display(HEAP H){
    
    for(int i = 0; i < H.last; i++){
        printf("%d ", H.arr[i]);
    }

    printf("\n");

}

int main(){

    HEAP H;
    initPOT(&H);
    insert(&H, 50);
    insert(&H, 40);
    insert(&H, 30);
    insert(&H, 17);
    insert(&H, 13);
    insert(&H, 12);
    insert(&H, 11);
    insert(&H, 7);
    insert(&H, 4);
    insert(&H, 6);
    insert(&H, 43);

    display(H);

    return 0;
}