//https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/* Node is defined as
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
    Node* segregate(Node* head) {
        Node* z = new Node(0);
        Node* o = new Node(1);
        Node* t = new Node(2);
        Node* tz= z;
        Node* to= o;
        Node* tt= t;
        Node* temp=head;
        while(temp!=NULL){
            Node* next = temp->next;
            temp->next = NULL;
            if(temp->data == 0){
                tz->next = temp;
                tz=tz->next;
            }else if(temp->data == 1){
                to->next = temp;
                to=to->next;
            }else if(temp->data == 2){
                tt->next = temp;
                tt=tt->next;
            }
            temp=next;
        }
        o=o->next;
        z=z->next;
        t=t->next;
        if(z==NULL){
            if(o==NULL){
                return t;
            }
            else{
                to->next=t;
                return o;
            }
        }else{
            if(o==NULL){
                tz->next=t;
           }
           else{
                tz->next=o;
                to->next=t;
           }
           return z;
        }
    }
};
