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

Node* input(int arr[], int index, int size){
    if(index>=size || arr[index]==-1)
        return NULL;
    Node* Tree = createNode(arr[index]);
    Tree->left=input(arr,2*index+1,size);
    Tree->right=input(arr,2*index+2,size);
    return Tree;
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
