//https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1


// optimal solution -> using divide and conqueor
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
        Node third(0);
        Node* temp=&third;
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
        return third.next;
    }
    Node* solve(vector<Node*>& arr, int l, int r){
        if(l==r)
            return arr[l];
        int mid = (l+r)/2;
        Node* left = solve(arr,l,mid);
        Node* right = solve(arr,mid+1,r);
        return merger(left,right);
    }
    Node* mergeKLists(vector<Node*>& arr) {
        return solve(arr, 0, (int)(arr.size() - 1));
    }
};
