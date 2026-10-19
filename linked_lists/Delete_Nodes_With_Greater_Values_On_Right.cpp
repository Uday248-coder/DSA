// https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1
// TC : O(N + N + N) -- two reversals and one pass that modifies.
// SC : O(1)

/* Structure of a Linked List node
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
    Node *compute(Node *head) {
        Node* rev=NULL;
        Node* curr=head;
        Node* next=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=rev;
            rev=curr;
            curr=next;
        }
        head=rev;
        Node* prev = rev;
        rev=rev->next;
        while(rev!=NULL){
            if(rev->data < prev->data){
                prev->next=rev->next;
            }
            else
                prev=rev;
            rev=rev->next;
        }
        rev=NULL;
        curr = head;
        next = head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=rev;
            rev=curr;
            curr=next;
        }
        return rev;
    }
};
