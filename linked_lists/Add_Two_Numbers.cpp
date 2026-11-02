//https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

//Brute-forced, but it wont work for extremely large numbers.
/*
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
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev =NULL;
        while(curr!=NULL){
            Node* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
  
    Node* addTwoLists(Node* head1, Node* head2) {
        long long x=0;
        long long y=0;
        while(head1!=NULL){
            x = (x+head1->data)*10;
            head1=head1->next;
        }
        while(head2!=NULL){
            y = (y+head2->data)*10;
            head2=head2->next;
        }
        x/=10;
        y/=10;
        long long z =x+y;
        Node* head3 = new Node(0);
        if(z==0)
            return head3;
        Node* temp = head3;
        while(z>0){
            temp->next = new Node(z%10);
            z/=10;
            temp=temp->next;
        }
        head3=reverse(head3->next);
        return head3;
    }
};
