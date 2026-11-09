//https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1


// I was tryind to di it manually where the question just wanted it to be converted to a int and just its multipication... i got pranked by the question :(
/* Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int key) {
        data = key;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    // Node* reverse(Node* head){
    //     Node* curr = head;
    //     Node* prev =NULL;
    //     while(curr!=NULL){
    //         Node* next = curr->next;
    //         curr->next = prev;
    //         prev=curr;
    //         curr=next;
    //     }
    //     return prev;
    // }
    // Node* remv_leading_zeros(Node* head){
    //     Node* org = head;
    //     while(head!=NULL && head->data ==0 && head->next!=NULL){
    //         head=head->next;
    //     }

    //     return head;
    // }
    // int multiplyTwoLists(Node* head1, Node* head2) {
    //     head1 = remv_leading_zeros(head1);
    //     head2 = remv_leading_zeros(head2);
    //     head1 = reverse(head1);
    //     head2 = reverse(head2);
    //     Node* head3 = new Node(0);
    //     Node* head3_cpy = head3;
    //     int carry = 0;
    //     int count = 0;
    //     int ans = 0;
    //     while(head2){
    //         int mul = head2->data;
    //         int curr_val = 0;
    //         Node* temp = head1;
    //         while(temp){
                
    //         }
            
    //     }
    // }
    int multiplyTwoLists(Node* head1, Node* head2) {
        int num1 = 0;
        int num2 = 0;
        while(head1){
            num1= num1 + head1->data;
            head1=head1->next;
            if(head1)
                num1*=10;
        }
        while(head2){
            num2= num2 + head2->data;
            head2=head2->next;
            if(head2)
                num2*=10;
        }
        int mod = 1e9 + 7;
        num1 %= mod;
        num2 %= mod;
        return (int)(((long long) num1*num2) % mod );
    }
};
