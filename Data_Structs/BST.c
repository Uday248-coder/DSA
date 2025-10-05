#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char d;
    struct Node* l;
    struct Node* r;
}Node;

Node* create(char v){
    Node* a = (Node*)malloc(sizeof(Node));
    a->d=v;
    a->r=NULL;
    a->l=NULL;
    return a;
}
Node* add(Node* x, char val){
    if(x == NULL ){
        return create(val);
    }
    
    if(val<x->d){
        x->l=add(x->l,val);
    }
    else{
        x->r=add(x->r,val);
    }
    
    return x;
}

void Postorder(Node* a){
    if(a==NULL){
        return;
    }
    Postorder(a->l);
    Postorder(a->r);
    printf("%c ",a->d);
}
void Preorder(Node* a){
    if(a==NULL){
        return;
    }
    printf("%c ",a->d);
    Postorder(a->l);
    Postorder(a->r);
}
void Inorder(Node* a){
    if(a==NULL){
        return;
    }
    Postorder(a->l);
    printf("%c ",a->d);
    Postorder(a->r);
}
char Min(Node* x){
    while(x->l != NULL)
        x=x->l;
    return x->d;
}
char Max(Node* x){
    while(x->r != NULL)
        x=x->r;
    return x->d;
}
void find_level(Node* a, int v, int lvl){
    if(a==NULL)
        printf("-1");
        
    if(v < a->d)
        find_level(a->l, v, lvl+1);
    else if(a->d < v)
        find_level(a->r, v, lvl+1);
    else
        printf("%d",lvl);
}

// to search for a value in the bst!
void search(Node* a, char t){
    if(a==NULL){
       printf("Character - %c is Not Found\n",t);
       return;
    }
    if(a->d < t)
        search(a->r, t);
    else if(a->d > t)
        search(a->l, t);
    else
        printf("Character - %c is Found\n",t);
}



Node* MIN(Node* a) {
    while (a && a->l != NULL)
        a = a->l;
    return a;
}
// to delete a node !! 
Node* del(Node* a, char c) {
    if (a == NULL)
        return NULL;

    if (c < a->d)
        a->l = del(a->l, c);
    else if (c > a->d)
        a->r = del(a->r, c);
    else {
        if (a->l == NULL) {
            Node* temp = a->r;
            free(a);
            return temp;
        } else if (a->r == NULL) {
            Node* temp = a->l;
            free(a);
            return temp;
        }
        Node* temp = MIN(a->r);
        a->d = temp->d;
        a->r = del(a->r, temp->d);
    }
    return a;
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
    printf("\nPre-Order : ");
    Preorder(a);
    printf("\nIn-Order : ");
    Inorder(a);
    printf("\nPost-Order : ");
    Postorder(a);
    printf("\n");
    char m=Min(a);
    char M=Max(a);
    printf("Minimum value: %c\nMaximum value: %c\n", m, M);
    return 0;
}
