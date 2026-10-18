//https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1


/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        Node* fast=head;
        Node* slow=head;
        Node* pre=fast;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            pre=slow;
            if(fast==slow){
                if (slow == head) {
                    Node* temp = head;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    temp->next = nullptr;
                    return;
                }
                slow=head;
                while(fast!=slow){
                    pre=fast;
                    fast=fast->next;
                    slow=slow->next;
                }
                pre->next=NULL;
                return;
            }
        }
    }
};
