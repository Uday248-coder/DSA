//https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

// TC : O(N)
// SC : O(1)

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    int length(Node* head){
        // iterative, O(1) space
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
    int len(Node* head){
        // recursive, O(N) space
        if(head==NULL){
            return 0;
        }
        return len(head->next) + 1;
    }
    Node* intersectPoint(Node* head1, Node* head2) {
        //  code here
        // since one list can be longer than the second list, we'll first find the lengths of each list
        // and then we shall cut or move forward in the longer list by 'difference between the lengths of the lists'
        // thereby eliminating the uneven lengths
        int l1 = length(head1);
        int l2 = length(head2);
        if(l2>l1){
            for(int i=1;i<=l2-l1;i++){
                head2=head2->next;
            }
        }else if(l1>l2){
            for(int i=1;i<=l1-l2;i++){
                head1=head1->next;
            }
        }
        while(head1!=NULL && head2!=NULL){
            if(head1 == head2){
                return head1;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return NULL;
    }
};
