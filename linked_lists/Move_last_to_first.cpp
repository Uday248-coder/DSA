//https://www.geeksforgeeks.org/problems/move-last-element-to-front-of-a-linked-list/1

// TC : O(N)
// SC : O(1)
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

*/
class Solution {
  public:
    Node *moveToFront(Node *head) {
        if(head->next==NULL)
            return head;
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        Node* last = temp->next;
        temp->next=NULL;
        last->next = head;
        return last;
    }
};
