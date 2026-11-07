//https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1




// uses divide and conqueor, hence faster
Node* solve(vector<Node*>& cols, int left, int right ){
        if(left == right)
            return cols[left];
        int mid = (right+left)/2;
        Node* l = solve(cols, left, mid);
        Node* r = solve(cols, mid+1, right);
        return merger(l,r);
    }
    
    Node* flatten(Node* head){
        if(!head)
            return head;
        vector<Node*> cols;
        for(Node* t=head; t; t=t->next){
            cols.push_back(t);
        }
        return solve(cols, 0, (int)cols.size()-1);
    }


// Not-Optimal
// TC : O(N*k)
// SC : O(N)

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  public:
    Node* merger(Node* head1, Node* head2){
        Node head(0);
        Node* temp = &head; 
        while(head1!=NULL && head2!=NULL){
            if(head1->data <= head2->data){
                temp->bottom=head1;
                head1=head1->bottom;
            }else{
                temp->bottom = head2;
                head2=head2->bottom;
            }
            temp=temp->bottom;
        }
        if(head1!=NULL)
            temp->bottom=head1;
        if(head2!=NULL)
            temp->bottom=head2;
        return head.bottom;
    }
    Node* flatten(Node* head) {
        if(head==NULL || head->next == NULL)
            return head;
        Node* list1 = head;
        
        Node* temp = head->next;
        while(temp!=NULL){
            Node* next = temp->next;
            list1->next = NULL;
            temp->next = NULL;
            list1 = merger(list1, temp);
            temp = next;
        }
        return list1;
    }

    // Recursive Method. still gives TLE on the last private testcase on GFG
    Node* flatten(Node* head){
        if(!head || !head->next){
            return head;
        }
        head->next = flatten(head->next);
        head = merger(head, head->next);
        return head;
    }

};
