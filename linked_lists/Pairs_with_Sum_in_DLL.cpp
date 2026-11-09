//https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
// TC : O(N/2)
// SC : O(1)
/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        // i'll use a two-pointer apporach for it
        vector<vector<int>> ans;
        if(!head || (!head->next && head->data!=target)){
            return ans;
        }
        Node* tail=head;
        while(tail->next!=NULL)
            tail=tail->next;
        while(head!=tail && head->data < tail->data){ // added the second check because in an even length list the head and tail can cross each other
            int sum = head->data + tail->data;
            if(sum==target){
                ans.push_back({head->data, tail->data});
                head=head->next;
                tail=tail->prev;
            }else if(sum > target){
                tail=tail->prev;
            }else{
                head=head->next;
            }
        }
        return ans;
    }
};
