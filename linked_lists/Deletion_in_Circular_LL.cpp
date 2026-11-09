//https://www.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1
/* Structure of Linked List Node
class Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int key) {
        Node* temp = head;
        if(!head || (head->next == head && head->data!=key))
            return head;
        if(head->next == head && head->data==key)
            return NULL;
        Node* prev = NULL;
        while(temp->next!=head){ // setting previous
            temp=temp->next;
        }
        prev = temp;
        temp=head;
        if(temp->data == key){
            prev->next = temp->next;
            temp->next =NULL;
            return prev->next;
        }
        else{
            prev=temp;
            temp=temp->next;
        }
        while(temp!=head){
            if(temp->data == key){
                prev->next = temp->next;
                temp->next =NULL;
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};
