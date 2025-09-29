#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Dequeue{
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
}DQ;

void init(DQ* a, int s){
    a->size=s;
    a->front=-1;
    a->rear=-1;
}
int Full(DQ* a){
    return (((a->front == 0)&&(a->rear == a->size-1)) || (a->front == a->rear + 1));
}
int Empty(DQ* a){
    return (a->front == -1);
}

void front_push(DQ* a, int val) {
    if (Full(a)) {
        printf("Deque is full\n");
        return;
    }
    if (Empty(a)) {
        a->front = a->rear = 0;
    } else if (a->front == 0) {
        a->front = a->size - 1;
    } else {
        a->front--;
    }
    a->data[a->front] = val;
}

void rear_push(DQ* a, int val) {
    if (Full(a)) {
        printf("Deque is full\n");
        return;
    }
    if (Empty(a)) {
        a->front = a->rear = 0;
    } else if (a->rear == a->size - 1) {
        a->rear = 0;
    } else {
        a->rear++;
    }
    a->data[a->rear] = val;
}

int front_pop(DQ* a) {
    if (Empty(a)) {
        printf("Deque is empty\n");
        return -1;
    }
    int val = a->data[a->front];
    if (a->front == a->rear) {
        a->front = a->rear = -1;
    } else if (a->front == a->size - 1) {
        a->front = 0;
    } else {
        a->front++;
    }
    return val;
}

int rear_pop(DQ* a) {
    if (Empty(a)) {
        printf("Deque is empty\n");
        return -1;
    }
    int val = a->data[a->rear];
    if (a->front == a->rear) {
        a->front = a->rear = -1;
    } else if (a->rear == 0) {
        a->rear = a->size - 1;
    } else {
        a->rear--;
    }
    return val;
}

