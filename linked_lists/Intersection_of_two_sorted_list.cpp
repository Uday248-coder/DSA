// https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

// TC: O(N + M)
// SC: O(N + M)


/* Structure of a Linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
    Node* head3= new Node(0);
    Node* temp = head3;
    while(head1!=NULL && head2!=NULL){
        if(head1->data == head2->data){
            temp->next = new Node(head1->data);
            head1=head1->next;
            head2=head2->next;
            temp=temp->next;
        }else if(head1->data < head2->data){
            head1=head1->next;
        }else{
            head2=head2->next;
        }
    }
    return head3->next;
    }
};
