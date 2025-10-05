#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    Node* l;
    Node* r;
}Node;

Node* create(int v){
    Node* x=(Node*)malloc(sizeof(Node));
    x->data=v;
    x->l=x->r=NULL;
    return x;
}


Node* getNode(Node* head, int ind){
    if(ind==-1){
        Node* temp=head;
        while(temp->r!=NULL)
            temp=temp->r;
        return temp;
    }
    Node* temp=head;
    for(int i=0;i<ind && temp!=NULL;i++){
        temp=temp->r;
    }
    return temp;
}

Node* InsertFirst(Node* head, int v){
    if(head == NULL)
        return create(v);
    Node* first = create(v);
    head->l=first;
    first->r=head;
    head=first;
    return head;
}

Node* Insert(Node* head, int ind, int v){
    if(head==NULL || ind==0)  {
        return InsertFirst(head,v);
        
    }
    Node* curr = getNode(head,ind-1);
    if(curr == NULL || curr->r==NULL)
        return InsertLast(head,v);
    Node* toAdd=create(v);
    toAdd->l=curr;
    toAdd->r=curr->r;
    curr->r->l=toAdd;
    curr->r=toAdd;
    return head;
}

Node* InsertLast(Node* head,int v){
    if(head==NULL)  {
        return InsertFirst(head,v);
        
    }

    Node* last = getNode(head,-1);
    Node* newLast = create(v);
    last->r=newLast;
    newLast->l=last;
    return head;
}

Node* deleteFirst(Node* head){
    if(head == NULL )
        return NULL;
    Node* temp=head;
    head = head->r;
    if(head!=NULL)
        head->l=NULL;
    free(temp);
    return head;
}

Node* delete(Node* head, int ind){
    if(head == NULL || ind ==0)
        return deleteFirst(head);
    Node* prev = getNode(head,ind-1);
    if(prev == NULL || prev->r == NULL)
        return head;
    Node* toDelete = prev->r;
    prev->r=toDelete->r;
    if(toDelete->r != NULL)
        toDelete->r->l = prev;
    free(toDelete);
    return head;
}

Node* deleteLast(Node* head){
    if(head==NULL)
        return NULL;
    if(head->r==NULL){
        free(head);
        return NULL;
    }
    Node* last=getNode(head,-1);
    last->l->r=NULL;
    free(last);
    return head;
} 

void printList(Node* head){
    while(head!=NULL){
        printf("%d <--> ",head->data);
        head=head->r;
    }
    printf("END");
}

// just for checking
int main(){
    Node* head = NULL;
    head = InsertLast(head, 100);
    head = InsertLast(head, 2);
    head = InsertFirst(head, 215);
    head = Insert(head, 2, 15);
    head = Insert(head, 2, 69);
    head = Insert(head, 1,11);
    printList(head);

    head = delete(head, 3);
    printList(head);

    head = deleteFirst(head);
    head = deleteLast(head);
    printList(head);

    return 0;
}
