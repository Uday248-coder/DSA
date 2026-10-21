//https://www.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

// TC: O(N)
// SC: O(1)

/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        Node* prev = head;
        Node* curr = head->next;
        while(curr!=NULL){
            while(prev->data == curr->data){
                curr=curr->next;
                if(curr==NULL){
                    break;
                }
            }
            prev->next = curr;
            if(curr!=NULL)
                curr=curr->next;
            prev=prev->next;
        }
        return head;
    }
};
