#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CAPACITY 10

struct kStacks 
{ 
    int *arr;   
    int *top;   
    int *next;  
    int cap, k; 
    int freeTop; 
};

void initkStacks(struct kStacks* ks, int k1, int n){
    ks->k = k1;
    ks->cap = n;
    ks->arr = (int*) malloc(ks->cap * sizeof(int));
    ks->top = (int*) malloc(ks->k * sizeof(int));
    ks->next = (int*) malloc(ks->cap * sizeof(int));

    for (int i = 0; i < ks->k; i++) 
        ks->top[i] = -1; 

    ks->freeTop = 0;
    for (int i=0; i<ks->cap-1; i++) 
        ks->next[i] = i+1; 
    ks->next[ks->cap-1] = -1;
}

int isFull(struct kStacks* ks) {  
    return (ks->freeTop == -1);  
}

int isEmpty(struct kStacks* ks, int sn) {  
    return (ks->top[sn] == -1); 
}

void push(struct kStacks* ks, int x, int sn) 
{ 
    if (isFull(ks)) 
    { 
        printf("\nStack Overflow\n"); 
        return; 
    } 

    int i = ks->freeTop;     
    ks->freeTop = ks->next[i]; 
    ks->next[i] = ks->top[sn]; 
    ks->top[sn] = i;
    ks->arr[i] = x; 
} 

int pop(struct kStacks* ks, int sn) 
{ 
    if (isEmpty(ks, sn)) 
    { 
        printf("\nStack Underflow\n"); 
        return INT_MAX; 
    }

    int i = ks->top[sn]; 
    ks->top[sn] = ks->next[i];   
    ks->next[i] = ks->freeTop; 
    ks->freeTop = i; 
    return ks->arr[i]; 
}

int main() 
{ 
    struct kStacks ks;
    int k = 3, n = 10; 
    initkStacks(&ks, k, n); 

    push(&ks, 15, 2); 
    push(&ks, 45, 2); 

    push(&ks, 17, 1); 
    push(&ks, 49, 1); 
    push(&ks, 39, 1); 

    push(&ks, 11, 0); 
    push(&ks, 9, 0); 
    push(&ks, 7, 0); 

    printf("Popped element from stack 2 is %d\n", pop(&ks, 2)); 
    printf("Popped element from stack 1 is %d\n", pop(&ks, 1)); 
    printf("Popped element from stack 0 is %d\n", pop(&ks, 0)); 

    return 0; 
}
