//https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1

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
