// Method 2(A space efficient implementation)

#include <stdio.h>
#include <stdlib.h>

struct TwoStacks {
    int* arr;
    int cap;
    int top1, top2;
};

void initTwoStacks(struct TwoStacks* ts, int n) {
    ts->cap = n;
    ts->arr = (int*)malloc(n * sizeof(int));
    ts->top1 = -1;
    ts->top2 = n;
}

void push1(struct TwoStacks* ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->top1++;
        ts->arr[ts->top1] = x;
    }
    else {
        printf("Stack Overflow");
        exit(1);
    }
}

void push2(struct TwoStacks* ts, int x) {
    if (ts->top1 < ts->top2 - 1) {
        ts->top2--;
        ts->arr[ts->top2] = x;
    }
    else {
        printf("Stack Overflow");
        exit(1);
    }
}

int pop1(struct TwoStacks* ts) {
    if (ts->top1 >= 0) {
        int x = ts->arr[ts->top1];
        ts->top1--;
        return x;
    }
    else {
        printf("Stack UnderFlow");
        exit(1);
    }
}

int pop2(struct TwoStacks* ts) {
    if (ts->top2 < ts->cap) {
        int x = ts->arr[ts->top2];
        ts->top2++;
        return x;
    }
    else {
        printf("Stack UnderFlow");
        exit(1);
    }
}

int main() {
    struct TwoStacks ts;
    initTwoStacks(&ts, 5);
    push1(&ts, 5);
    push2(&ts, 10);
    push2(&ts, 15);
    push1(&ts, 11);
    push2(&ts, 7);
    printf("Popped element from stack1 is %d\n", pop1(&ts));
    push2(&ts, 40);
    printf("Popped element from stack2 is %d\n", pop2(&ts));
    return 0;
}
