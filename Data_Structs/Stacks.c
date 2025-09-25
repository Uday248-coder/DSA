#include <stdlib.h>
#include <stdio.h>
#define MAX 1000
typedef struct {
    int stack[MAX];
    int top;
}S;

void push(S* a, int val){
    if(a->top ==MAX-1){
        printf("OVERFLOW!");
    }
    else{
        a->stack[++(a->top)]=val;
    }
}

int pop(S* a){
    if(a->top ==-1){
        printf("UNDERFLOW!");
        return -99999;
    }
    else{
        return a->stack[(a->top)--];
    }
}
int peek(S* a){
    if(a->top ==-1){
        printf("EMPTY!");
        return -99999;
    }
    else{
        return a->stack[a->top];
    }
}
