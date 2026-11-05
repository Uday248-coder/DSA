//https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

// TC : O(N)
// SC : O(1)

/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        Node* temp = head;
        unordered_map<Node*,Node*> map;
        while(temp!=NULL){
            map[temp] = new Node(temp->data);
            temp=temp->next;
        }
        temp=head;
        Node* clone = new Node(temp->data);
        Node* curr = clone;
        while(temp!=NULL){
            curr->next = map[temp->next];
            curr->random = map[temp->random];
            curr=curr->next;
            temp=temp->next;
        }
        return clone;
    }
};
