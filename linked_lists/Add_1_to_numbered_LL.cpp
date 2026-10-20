//https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

// TC: O(N + N + N) // reverse + modification + reverse
// SC: O(1)

/* Structure of linked list Node
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
        Node* curr=head;
        Node* prev=NULL;
        Node* next=head;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        head = reverse(head);
        Node* curr = head;
        while(true){
            head->data +=1;
            if(head->data <10)
                break;
            head->data %=10;
            if(head->next == NULL){
                head->next = new Node(0);
            }
            head=head->next;
        }
        head = reverse(curr);
        return head;
    }
};
