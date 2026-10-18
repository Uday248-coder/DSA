// https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1






// i feel for questions of loops and stuff.. i must use slow and fast pointer 
//but i also got one more idea.. mark each node visited and if u land on any visited node, return true
// lets first do visited one..
// since the data according to question's constraint is always positive (1,10^3), i can mark a node as visited by making it negative.
//TC : O(N)
//SC : O(1)

class Solution {
  public:
    bool detectLoop(Node* head) {
        
        Node* curr =head;
        while(curr!=NULL){
            if(curr->data <0)
                return true;
            curr->data *= -1;
            curr=curr->next;
        }
        return false;
    }
};
