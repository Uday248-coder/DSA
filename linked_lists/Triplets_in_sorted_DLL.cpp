//https://www.geeksforgeeks.org/dsa/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/

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
        // 3-SUM approach
        vector<vector<int>> ans;
        if(!head || (!head->next && head->data!=target)){
            return ans;
        }
        Node* tail=head;
        while(tail->next!=NULL)
            tail=tail->next;
        for(Node* t=head; t; t=t->next){
          Node* sec = t->next;
          Node* thr = tail;
          while(sec->data <=thr->data){
            int sum = t->data + sec->data + thr->data;
            if(sum > target){
              thr=thr->prev;
            }else if(sum<target){
              sec = sec->next;
            }else{
              ans.push_back({t->data, sec->data, thr->data});
              sec=sec->next;
              thr=thr->prev;
            } 
          }
        }
        return ans;
    }
};
