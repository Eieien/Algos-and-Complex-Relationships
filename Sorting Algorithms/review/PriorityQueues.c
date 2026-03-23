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

void maxHeapifyUp(HEAP* H){
    for(int i = H->last; H->arr[parentIdx(i)] < H->arr[i]; i = parentIdx(i)){
        int temp = H->arr[i];
        H->arr[i] = H->arr[parentIdx(i)];
        H->arr[parentIdx(i)] = temp;
    }
}

void maxHeapify(HEAP* H, int i){

    int largest = i;
    int r = RightChildIdx(i);
    int l = leftChildIdx(i);
    int n = H->last;

    if(l < n && H->arr[l] > H->arr[largest]){
        largest = l;
    }

    if(r < n && H->arr[r] > H->arr[largest]){
        largest = r;
    }

    if(largest != i){
        int temp = H->arr[largest];
        H->arr[largest] = H->arr[i];
        H->arr[i] = temp;
    
        maxHeapify(H, largest);
    }

}

void minHeapify(HEAP* H, int i){
    int smallest = i;
    int r = RightChildIdx(i);
    int l = leftChildIdx(i);
    int n =H->last;
    if(l < n && H->arr[l] < H->arr[smallest]){
        smallest = l;
    }

    if(r < n && H->arr[r] < H->arr[smallest]){
        smallest = r;
    }

    if(smallest != i){
        
        int temp = H->arr[smallest];
        H->arr[smallest] = H->arr[i];
        H->arr[i] = temp;

        minHeapify(H, smallest);
    }
}

void deleteMax(HEAP* H){
    int temp = H->arr[0];
    H->arr[0] = H->arr[H->last - 1];
    H->arr[H->last - 1] = temp;
    // printf("%d \n", H->arr[H->last - 1]);
    H->last--;
    maxHeapify(H, 0);
}

void heapSort(HEAP* H){
    int last = H->last;
    for(int i = 0; i < last; i++){
        deleteMax(H);
    }

    H->last = last;

}

void insert(HEAP* H, int val){
    
    H->arr[H->last] = val;
    maxHeapifyUp(H);
    
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
    insert(&H, 40);
    insert(&H, 30);
    insert(&H, 17);
    insert(&H, 7);
    insert(&H, 4);
    insert(&H, 4);
    insert(&H, 4);
    insert(&H, 50);
    insert(&H, 6);
    insert(&H, 43);
    
    display(H);
    // deleteMax(&H);
    // deleteMax(&H);
    // deleteMax(&H);
    // deleteMax(&H);
    // deleteMax(&H);
    // deleteMax(&H);
    // deleteMax(&H);

    heapSort(&H);
    display(H);

    return 0;
}