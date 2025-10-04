#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char d;
    struct Node* n;
    struct Node* p;
}Node;

Node* create(char v){
    Node* a = (Node*)malloc(sizeof(Node));
    a->d=v;
    a->n=NULL;
    a->p=NULL;
    return a;
}
Node* add(Node* x, char val){
    if(x == NULL ){
        return create(val);
    }
    
    if(val<x->d){
        x->p=add(x->p,val);
    }
    else{
        x->n=add(x->n,val);
    }
    
    return x;
}

char Min(Node* x){
    while(x->p != NULL)
        x=x->p;
    return x->d;
}
char Max(Node* x){
    while(x->n != NULL)
        x=x->n;
    return x->d;
}

int main(){
    int num;
    scanf("%d",&num);
    Node* a=NULL;
    for(int i=0;i<num;i++){
        char c;
        scanf(" %c",&c);
        a=add(a,c);
    }
    char m=Min(a);
    char M=Max(a);
    printf("Minimum value: %c\nMaximum value: %c\n", m, M);
    return 0;
}
