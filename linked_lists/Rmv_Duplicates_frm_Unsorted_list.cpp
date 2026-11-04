//https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1


// used unordered set to keep track of all the inputs.

/* Structure of linked list Node
class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        if(head==NULL|| head->next==NULL){
            return head;
        }
        unordered_set<int> isPresent;
        Node* curr = head;
        Node* prev = NULL;
        while(curr!=NULL){
            if(isPresent.count(curr->data)){
                prev->next = curr->next;
                curr->next = NULL;
                curr = prev->next;
            }else{
                isPresent.insert(curr->data);
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};
