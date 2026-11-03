//https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

// TC: O(n)
// SC: O(1)
// Broke the list into odd and even list and then conjoined the even list with the odd one

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
}; */
class Solution {
  public:
    Node* divide(Node* head) {
        Node* odd = new Node(0); // head of odd list with a dummy node
        Node* even = new Node(1); // head of even list with a dummy node
        Node* to=odd; // to traverse odd list
        Node* te=even; // to traverse even list
        Node* temp=head;
        while(temp!=NULL){
            Node* next = temp->next;
            temp->next = NULL;
            if(temp->data%2==0){
                te->next = temp;
                te=te->next;
            }else{
                to->next = temp;
                to=to->next;
            }
            temp=next;
        }
        odd = odd->next;
        even = even->next;
        if(even != NULL){
            te->next = odd;
            return even;}
        else{
            return odd;
        }
    }
};
