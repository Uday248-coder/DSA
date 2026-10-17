//https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

// Two-Pointer Approach
/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        Node* curr=head;
        Node* ans =head;
        int gap=0;
        while(curr!=NULL){
            if(gap<k)
                gap++;
            else
                ans=ans->next;
            curr=curr->next;
        }
        if(gap<k)
            return -1;
        return ans->data;
    }
};




//Brute-Force 
//TC : O(N)
//SC : O(1)

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        int size=0;
        Node* temp = head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        if(size<k)
            return -1;
        temp=head;
        for(int i=0;i<size-k;i++){
            temp=temp->next;
        }
        return temp->data;
    }
};
