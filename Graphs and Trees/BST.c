#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int value;
    struct node* LC;
    struct node* RC;

}*Node;


void preOrder(Node H){

    if(H != NULL){
        printf("%d ", H->value);
        preOrder(H->LC);
        preOrder(H->RC);
    }
}

void inOrder(Node H){

    if(H != NULL){
        inOrder(H->LC);
        printf("%d ", H->value);
        inOrder(H->RC);
    }
}

void postOrder(Node H){

    if(H != NULL){
        postOrder(H->LC);
        postOrder(H->RC);
        printf("%d ", H->value);
    }
}

void insert(Node* H, int val){

    Node* curr = H;

    for(curr = H; *curr != NULL;){
        curr = ((*curr)->value > val) ? &(*curr)->LC : &(*curr)->RC;
    }
    *curr = malloc(sizeof(struct node));
    (*curr)->value = val;
    (*curr)->LC = NULL;
    (*curr)->RC = NULL;
}

void delete(Node*H, int val){

    Node* curr = H;

    for(curr = H; *curr != NULL && (*curr)->value != val;){
    
        curr = ((*curr)->value > val) ? &(*curr)->LC : &(*curr)->RC;
    }
    

    if(*curr != NULL){
        Node temp = *curr;
        //leaf
        if((*curr)->LC == NULL && (*curr)->RC == NULL){
            *curr = NULL;
            free(temp);
        }
    
        // If on childlren
    
        else if((*curr)->LC == NULL){
            *curr = (*curr)->RC;
            free(temp);
        }
    
        else if((*curr)->RC == NULL){
            *curr = (*curr)->LC;
            free(temp);
        }
    
        else{
            Node* successor = &(*curr)->RC;
    
            while((*successor)->LC != NULL){
                successor = &(*successor)->RC;
            }
    
            (*curr)->value = (*successor)->value;
    
            Node temp2 = *successor;
            *successor = (*successor)->RC;
            free(temp2);
        }

    }

}

int main(){
    
    Node H;

    insert(&H, 50);
    insert(&H, 30);
    insert(&H, 20);
    insert(&H, 40);
    insert(&H, 25);
    insert(&H, 10);
    insert(&H, 70);
    insert(&H, 80);

    delete(&H, 50);

    printf("PRE-ORDER: ");
    preOrder(H);
    printf("\n");
    // printf("IN-ORDER: ");
    // inOrder(H);
    // printf("\n");
    // printf("POST-ORDER: ");
    // postOrder(H);
    // printf("\n");


    return 0;
}