//https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int psum=0;
        unordered_map<int,ListNode*> map;
        ListNode dummy(0);
        dummy.next=head;
        map[dummy.val] = &dummy;
        while(head!=NULL){
            psum +=head->val;
            if(map.contains(psum)){
                ListNode* temp = dummy.next;
                int temp_sum =0;
                while(temp!=map[psum]->next){
                    temp_sum += temp->val;
                    temp=temp->next;
                }
                while(temp!=head){
                    temp_sum +=temp->val;
                    map.erase(temp_sum);
                    temp=temp->next;
                }
                map[psum]->next = head->next;
                head->next=NULL;
                head = map[psum]->next;
            }else{
                map[psum]=head;
                head=head->next;
            }
        }
        return dummy.next;
    }
};
