//https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

// TC: O(N) iterative approach
// SC: O(1)

/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = head;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};
