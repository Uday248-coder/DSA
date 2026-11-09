//https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        if(!head || !head->next){
            return head;
        }
        Node* curr = head;
        Node* p = NULL;
        while(curr!=NULL){
            Node* next = curr->next;
            curr->next = curr->prev;
            curr->prev = next;
            p=curr;
            curr=next;
        }
        return p;
    }
};
