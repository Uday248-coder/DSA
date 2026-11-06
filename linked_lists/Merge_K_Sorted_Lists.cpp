//https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1


// Non-optimal solution -> giving TLE for large inputs.
/* Linked List Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* merger(Node* head1, Node* head2){
        Node* third=new Node(0);
        Node* temp=third;
        while(head1!=NULL && head2!=NULL){
            if(head1->data <=head2->data){
                temp->next=head1;
                head1=head1->next;
            }else{
                temp->next=head2;
                head2=head2->next;
            }
            temp=temp->next;
        }
        if(head1!=NULL){
            temp->next=head1;
        }
        if(head2!=NULL){
            temp->next=head2;
        }
        return third->next;
    } 
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        Node* l1 = arr[0];
        for(int i=1;i<arr.size();i++){
            l1 = merger(l1,arr[i]);
        }
        return l1;
    }
};
