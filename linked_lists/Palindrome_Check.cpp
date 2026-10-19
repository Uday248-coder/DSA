//https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

// TC: O(N/2 + N/2 + N/2)
// SC: O(1)


/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        Node* slow = head;
        Node* fast = head;
        Node* pre=slow;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            pre=slow;
            slow=slow->next;
        }
        pre->next=NULL;
        //reusing variables here for reversing
        fast = slow; //will be used as next
        pre=NULL; // will be used as previous
        while(slow!=NULL){
            fast = slow->next;
            slow->next=pre;
            pre=slow;
            slow=fast;
        }
        
        // head of left part is head
        // head node of right part is pre
        
        while(pre!=NULL && head!=NULL){
            if(pre->data != head->data){
                return false;
            }
            pre=pre->next;
            head=head->next;
        }
        return true;
    }
};
