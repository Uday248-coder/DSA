#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int val){
    Node* x = (Node*)malloc(sizeof(Node));
    x->data=val;
    x->left=NULL;
    x->right=NULL;
    return x;
}
// creating tree from user inputed values which were stored in array initially...
Node* input(int arr[], int index, int size){
    if(index>=size || arr[index]==-1)
        return NULL;
    Node* Tree = createNode(arr[index]);
    Tree->left=input(arr,2*index+1,size);
    Tree->right=input(arr,2*index+2,size);
    return Tree;
}

// DFS tailored Traversals -- Pre, Post & In order
void Post_order(Node* x){
    if(x==NULL)
        return;
    //LRN
    Post_order(x->left);
    Post_order(x->right);
    printf("%d\t",x->data);
}
void Pre_order(Node* x){
    if(x==NULL)
        return;
    //NLR
    printf("%d\t",x->data);
    Pre_order(x->left);
    Pre_order(x->right);
}
void In_order(Node* x){
    if(x==NULL)
        return;
    //LNR
    In_order(x->left);
    printf("%d\t",x->data);
    In_order(x->right);
}

// BFS tailored Traversals -- Level-order & Reverse Level-Order
typedef struct 
{
    Node* arr[5000];
    int head,rear;
}Queue;

void enqueue(Queue* a, Node* x){
    a->arr[a->rear++]=x;
}

Node* dequeue(Queue* a){
    return a->arr[a->head++];
}

int is_empty(Queue* x){
    return x->head==x->rear;
}

int* Lvl_order(Node* head, int size){
    int* ans = (int*)malloc(sizeof(int)*size);
    if(head==NULL)
    return ans;
    Queue p;
    p.head=p.rear=0;
    int i=0;
    enqueue(&p,head);
    while(!is_empty(&p)){
        Node* cur = dequeue(&p);
        ans[i++]=cur->data;
        if(cur->left) enqueue(&p,cur->left);
        if(cur->right) enqueue(&p,cur->right);
    }
    return ans;
}

int* Rev_Lvl_order(Node* head,int size){
    int* org = Lvl_order(head,size);
    int* ans = (int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        ans[i]=org[size-1-i];
    }
    free(org);
    return &ans;
}

int main(void){
    int arr[2000];
    int count=0;
    printf("Enter the elements of tree::\n");
    while(scanf("%d",&arr[count]) ==1){
        count++;
    }
    Node* Tree = input(arr,0,count);
    printf("%-20s :: ", "Pre-Order Traversal"); // left aligned -- pretty printing !!
    Pre_order(Tree);
    printf("\n");
    printf("%-20s :: ", "In-Order Traversal");
    In_order(Tree);
    printf("\n");
    printf("%-20s :: ", "Post-Order Traversal");
    Post_order(Tree);
    printf("\n");
    return 0;
}
