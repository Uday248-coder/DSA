//https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        int len=0;
        Node* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len<k){
            
            Node* curr=head;
            Node* prev=NULL;
            
            while(curr!=NULL){
                Node* next = curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
        Node* prev=NULL;
        Node* curr=head;
        for(int i=1;i<=k;i++){
            Node* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        Node* rem_list = reverseKGroup(curr, k);
        head->next=rem_list;
        return prev;
    }
};
