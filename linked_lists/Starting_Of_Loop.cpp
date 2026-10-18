//https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

//slow and fast pointer approach
class Solution {
  public:
    int cycleStart(Node* head) {
        Node* fast = head;
        Node* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                slow = head;
                while(slow!=fast){
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow->data;
            }
        }
        return -1;
    }
};



// Used Visited Marking Technique.
class Solution {
  public:
    int cycleStart(Node* head) {
        Node* curr = head;
        while(curr!=NULL){
            if(curr->data < 0)
                return -1*curr->data;
            curr->data *=-1;
            curr=curr->next;
        }
        return -1;
    }
};
