//https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

















// Not-Optimal
// TC : O(N*k)
// SC : O(N)

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  public:
    Node* merger(Node* head1, Node* head2){
        Node* head = new Node(0);
        Node* temp = head; 
        while(head1!=NULL && head2!=NULL){
            if(head1->data <= head2->data){
                temp->bottom=head1;
                head1=head1->bottom;
            }else{
                temp->bottom = head2;
                head2=head2->bottom;
            }
            temp=temp->bottom;
        }
        if(head1!=NULL)
            temp->bottom=head1;
        if(head2!=NULL)
            temp->bottom=head2;
        return head->bottom;
    }
    Node* flatten(Node* head) {
        if(head==NULL || head->next == NULL)
            return head;
        Node* list1 = head;
        
        Node* temp = head->next;
        while(temp!=NULL){
            Node* next = temp->next;
            // list1->next = NULL;
            // temp->next = NULL;
            list1 = merger(list1, temp);
            temp = next;
        }
        return list1;
    }
};
