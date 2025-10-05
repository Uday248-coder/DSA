// created linked list in c after Java!!

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* create_single(int val){
    Node* a=(Node*)malloc(sizeof(Node));
    a->data=val;
    a->next=NULL;
    return a;
}

Node* getNode(Node* head, int ind){
    Node* temp=head; // will store head node for local traversing
    if(ind==-1){ // this is a speacial case, if i want the last node, i will search until NULL is encountered!
        // reason for using this as a case is because we dont have a size variable, that is robustly getting updated per instruction call for the list, right!?
        while(temp->next!=NULL)
            temp=temp->next;
        return temp;
    }

    for(int i=0;i<ind;i++){
        temp=temp->next;
    }
    return temp;
}

void insertFirst(Node** h, int val){ // using ** because we actually are making change in the head node na, we are doing the changes here itself, 
    //if we would have sent back the changes as return, then we could have used *head or whatever..but the entire change is being made here, hence..

    // the most basic analogy, this **h pointer will point the head which is the pointer to the first node of our list, right?
    // in this function, we modify the list itself, but the **h pointer will still point to head as these changes are made in the vicinity if this function itself
    //and the scope forces these changes to not exist beyond this function, since we arnt returning those changes.
    // so to avoid this , we send the pointer of head, so that after the changes the main pointer itself points to the changed list !
    Node* n=create_single(val);
    n->next=*h;
    *h = n;
}

void insertion(Node** head, int val, int ind){
    if(ind == 0)
    {
        insertFirst(head,val);
        return;
    }    

    Node* temp=getNode(*head,ind-1);
    Node* n=create_single(val);
    n->next=temp->next;
    temp->next = n;
}
void insertLast(Node** head, int val){
    if(*head==NULL){
        insertFirst(head,val);
        return;
    }
    Node* last = getNode(*head,-1);
    last->next=create_single(val);
}

void deleteFirst(Node** head){
    if (*head == NULL) return;
    Node* temp=*head;
    *head=(*head)->next;
    free(temp);//freeing memory..
}

void delete(Node** head, int ind){
    if(*head == NULL)
        return;
    if(ind == 0){
        deleteFirst(head);
        return ;
    }

    Node* prev= getNode(*head,ind-1);
    if(prev == NULL || prev->next ==NULL) return;

    Node* toDelete = prev->next;
    prev->next=toDelete->next;
    free(toDelete);
}

void deleteLast(Node** head){
    if(*head == NULL)
        return;
    if((*head)->next == NULL){
        free(*head);
        *head=NULL;
        return;
    }
    Node* secondLast=*head;
    while(secondLast->next->next !=NULL)
        secondLast=secondLast->next;
    free(secondLast->next);
    secondLast->next=NULL;
}

void printList(Node* head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("END\n");
}

//smaple main method, just to check working
int main(void){
    Node* head = NULL;
    insertLast(&head, 10);
    insertLast(&head, 20);
    insertFirst(&head, 5);
    insertion(&head, 15, 2);
    printList(head);

    delete(&head, 2);
    deleteLast(&head);
    printList(head);
    return 0;
}
