// basic circular queue

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 500  //any value u wish to have here

typedef struct {
    int data[MAXSIZE];
    int front,rear;
    int SIZE;
}Queue;

void init(Queue* a, int s){
    a->rear=0;
    a->front=0;
    if(s > MAXSIZE) 
      s = MAXSIZE;
    a->SIZE = s;

}

int isFull(Queue* x){
// for basic queue:: if(x->front == x->rear) <<<< this is the full condition!
    if((x->rear+1)%x->SIZE == x->front ){
        printf("Queue is FULL!");
        return 1;
    }
    return 0;
}
int isEmpty(Queue* x){
// for basic queue:: if(x->rear == 0) <<<< this is the empty condition!
    if(x->rear == x->front){
        printf("Queue is Empty!");
        return 1;
    }
    return 0;
}

void enqueue(Queue* a, int val){
    if(isFull(a))
        printf("No element enqueued!\n");
    else{
        printf("Element Enqeued : %d\n",val);
        a->data[a->rear] = val;
      // for basic queue -->>> a->rear ++ ;
        a->rear = (a->rear +1)%a->SIZE;
    }
}
void dequeue(Queue* a){
    if(isEmpty(a))
        printf("No element Dequeued!\n");
    else{
        int val=a->data[a->front];
      // for basic queue -->>> a->front ++ ;
        a->front = (a->front+1)%a->SIZE;
        printf("Element Deqeued : %d\n",val);
    }
}

// for basic queue
// void reset(Queue* a){
//   init(a, a->SIZE);
// }
