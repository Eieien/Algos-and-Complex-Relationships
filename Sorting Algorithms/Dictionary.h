#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10
typedef struct Node{

    struct Node *link;
    int val;

}*LIST, *Node;

typedef LIST DICTIONARY[MAX];

#endif