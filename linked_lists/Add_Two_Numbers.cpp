//https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

//TC: O(n+m)
//SC : O(n)
// Corrected Implementations
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
    Node* remv_leading_zeros(Node* head){
        Node* org = head;
        while(head!=NULL && head->data ==0 && head->next!=NULL){
            head=head->next;
        }
        
        return head;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        head1 = remv_leading_zeros(head1);
        head2 = remv_leading_zeros(head2);
        head1 = reverse(head1);
        head2 = reverse(head2);
        Node* head3 = new Node(0);
        Node* head3_cpy = head3;
        int carry=0;
        while(head1!=NULL || head2!=NULL || carry!=0){
            if(head1!=NULL){
                head3->data += head1->data; 
                head1=head1->next;
            }
            if(head2!=NULL){
                head3->data += head2->data;
                head2=head2->next;
            }
            if(carry!=0){
                head3->data += carry; 
            }
            if(head3->data >9){
                carry = head3->data/10;
                head3->data %= 10; 
            }else{
                carry=0;
            }
            head3->next = new Node(0);
            head3=head3->next;
        }
        
        head3 = reverse(head3_cpy);
        head3 = remv_leading_zeros(head3);
        return head3;
    }
};


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
