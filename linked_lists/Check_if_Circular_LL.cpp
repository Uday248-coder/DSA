// https://www.geeksforgeeks.org/problems/circular-linked-list/1


/* Linked List Node Structure
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
    bool isCircular(Node *head) {
        // code here
        Node* temp=head;
        while(temp){
            if(!temp->next)
                return false;
            if(temp->next == head)
                return true;
            temp=temp->next;
        }
        return false;
    }
};
