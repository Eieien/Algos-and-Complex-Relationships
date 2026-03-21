#ifndef DICTBUCKET_H
#define DICTBUCKET_H


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{

    struct Node *link;
    int val;

}*LIST, *Node;


LIST* createBuckets(int amount);
void insertSorted(LIST B[], int key, int val);

void displayBuckets(LIST B[], int amount){
    for(int i = 0; i < amount; i++){
        printf("%d ", i);
        if(B[i] == NULL){
            printf("NULL\n");
        }else{
            
            for(Node curr = B[i]; curr != NULL; curr = curr->link){
                printf("%d -> ", curr->val);
            }
            printf("NULL\n");
        }
        printf("\n");

    }
}

LIST* createBuckets(int amount){
    LIST* buckets = (LIST*)malloc(sizeof(LIST) * amount);
    for(int i = 0; i < amount; i++){
        buckets[i] = NULL;
    }
    return buckets;
}

int getRange(int min, int max, int amount){
    return ((max - min) / amount) + 1;
}

int hash(int num, int min, int range){
    return (num - min) / range;
}

void insertSorted(LIST B[], int key, int val){
    Node* curr;

    for(curr = &B[key]; *curr != NULL && (*curr)->val < val; curr = &(*curr)->link){}
    Node node = malloc(sizeof(struct Node));
    node->val = val;
    node->link = *curr;

    *curr = node;
}

void freeBuckets(LIST B[]){
    free(B);
}

#endif