//https://www.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1
// TC : O(N)
// SC : O(1)
/* Structure of a doubly link list node
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int length(Node* head){
        int c=0;
        while(head!=NULL){
            c++;
            head=head->next;
        }
        return c;
    }
    Node *rotateDLL(Node *head, int k) {
        Node* start=head;
        Node* end=head;
        int size = length(head);
        k = k%size;
        if(size<=1 || k==0)
            return head;
        while(end->next!=NULL){
            end=end->next;
        }
        while(k-->0){
            start=start->next;
        }
        Node* prev= start->prev;
        prev->next = NULL;
        start->prev=NULL;
        end->next=head;
        head->prev=end;
        return start;
    }
};
