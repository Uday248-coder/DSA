//https://www.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1
/* Circular Linked List Node Structure
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    vector<Node *> splitList(Node *head) {
        vector<Node*> ans;
        if(!head){
            ans.push_back(NULL);
            ans.push_back(NULL);
            return ans;
        }
        if(head->next == head){
            ans.push_back(head);
            ans.push_back(head);
            return ans;
        }
        Node* fast = head;
        Node* slow = head;
        while(fast->next!=head && fast->next->next!=head){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next->next==head)
            fast=fast->next;
            
        Node* head2 = slow->next;
        slow->next = head;
        fast->next = head2;
        ans.push_back(head);
        ans.push_back(head2);
        return ans;
    }
};
