---
Date Created: "0316"
Status: "#idea"
topics: "[[Algorithms and Complexity]]"
tags:
  - Sorting_algorithms
---
# Bucket Sort
A Distributive sorting algorithm that places elements into groups and sorts elements within those groups, then concatenate all buckets by starting with the first bucket up to the last bucket to get the sorter array

In C,  you can use Dictionaries or array of lists to act as buckets storing the values of each element within the bucket

The amount of buckets to be used depends if the data is uniformly distributed or not (these are just common methods used)
- n = # of elements
- `num_buckets = sqrt(n)` for general use and if you don't have a clear view of the distribution of data
- `num_buckets = n` for uniform data
The goal is to have buckets that are balanced so that one bucket cannot hog all the data at once, if it's unbalanced, the time complexity will increase.
# Formulas
## Bucket Range
The range of elements that is needed in the bucket 
Add 1 to add extra space for the max value hash index
$$
bucket range = \frac{max - min}{NumOfBuckets} + 1
$$
```
int getRange(int min, int max, int amount){
    return ((max - min) / amount) + 1;
}
```
## Bucket index
The hash function to store the element within the specific bucket
$$
bucketidx = \frac{num-min}{bucketrange}
$$
```
int hash(int num, int min, int range){
    return (num - min) / range;
}
```
# Process
1. Find the min and max and get the range
2. Use the has function on the current element and place it on the correct bucket
3. Sort each bucket (Most optimal way of sorting buckets is counting sort)
4. Concatenate all buckets starting from the first bucket to the last bucket and place the concatenation in the input array

# Dictionary or Array of arrays?
Best performance is array or arrays since it's cache performance is better than that of linked lists and no additional memory is allocated on demand

# Dictionary Implementation (My Ver.)
## Data Structure
```
typedef struct Node{
    struct Node *link;
    int val;
}*LIST, *Node;
```
## Init Buckets
```
LIST* createDictionary(int amount){
    LIST* buckets = (LIST*)malloc(sizeof(LIST) * amount);
    for(int i = 0; i < amount; i++){
        buckets[i] = NULL;
    }
    return buckets;
}
```
## Insert Item to Bucket
```
void insertSorted(LIST B[], int key, int val){
    Node* curr;

    for(curr = &B[key]; *curr != NULL && (*curr)->val < val; curr = &(*curr)->link){}
    Node node = malloc(sizeof(struct Node));
    node->val = val;
    node->link = *curr;

    *curr = node;
}
```
## Free Bucket
```
void freeBuckets(LIST B[]){
    free(B);
}
```
## Sorting Algorithm
```
void bucketSort(int arr[], int len){
    int amount = (int)sqrt(len);
    LIST* buckets = createDictionary(amount);
    int min = arr[0];
    int max = arr[0];
    // find the minimum and maximum
    for(int i = 0; i < len; i++){
        if(min > arr[i]){
            min = arr[i];
        }

        if(max < arr[i]){
            max = arr[i];
        }
    }

    int range = getRange(min, max, amount);
    printf("%d \n", range);

    for(int i = 0; i < len; i++){
        int key = hash(arr[i], min, range);
        insertSorted(buckets, key, arr[i]);        
    }

    displayBuckets(buckets, amount);

    int k = 0;
    for(int i = 0; i < amount; i++){

        for(Node* curr = &buckets[i]; *curr != NULL;){
            arr[k] = (*curr)->val;
            k++;
            Node temp = *curr;
            curr = &(*curr)->link;
            free(temp);
        }
    }

    freeBuckets(buckets);
}
```
# Array of Lists Implementation
```
#define SENTINAL 99999999
```
## Display
```
void displayArrayBuckets(int** buckets, int numBuckets, int range){

    for(int i = 0; i < numBuckets; i++){
        printf("%d -> ", i);
        for(int j = 0; j < range && buckets[i][j] != SENTINAL; j++){
            printf("%d -> ", buckets[i][j]);
        }
        printf("\n");
    }
}
```
## Init Buckets
```
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
```
## Free Buckets
```
void freeArrayBuckets(int** buckets, int numBuckets){

    for(int i = 0; i < numBuckets; i++){
        free(buckets[i]);
    }
    free(buckets);
}
```
## Insert and Sort Buckets
```
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
```
## Sorting Algorithm
```
void ArrayBucketSort(int arr[], int len){
    int numBuckets = (int)sqrt(len);
    
    int min = arr[0], max = arr[0];

    for(int i = 0; i < len; i++){
        if(min > arr[i]){
            min = arr[i];
        }

        if(max < arr[i]){
            max = arr[i];
        }
    }
    
    int range = getRange(min, max, numBuckets);

    int** buckets = createArrayBuckets(numBuckets, range);

    for(int i = 0; i < len; i++){
        int key = hash(arr[i], min, range);
        insertIntoBucket(buckets, arr[i], key, range);        
    }

    sortBuckets(buckets, numBuckets, range);
    displayArrayBuckets(buckets, numBuckets, range);

    int i = 0;
    for(int j = 0; j < numBuckets; j++){

        for(int k = 0; k < range && buckets[j][k] < SENTINAL; k++){
            arr[i] = buckets[j][k];
            i++;
        }
    }
    
    freeArrayBuckets(buckets, numBuckets);
}
```
# Out-place sorting Algorithm
Since you need buckets to store the values you are distributing, it is an out-place sorting algorithm because of that

[[In-place and Out-place sorting algorithms]]

---
# References