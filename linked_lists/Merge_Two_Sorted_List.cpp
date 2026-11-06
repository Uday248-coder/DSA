//https://leetcode.com/problems/merge-two-sorted-lists/

// TC: O(N+M)
// SC: O(1)

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* merged = new ListNode(0);
        ListNode* head3 = merged;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                head3->next = temp1;
                temp1=temp1->next;
            }else{
                head3->next = temp2;
                temp2=temp2->next;
            }
            head3=head3->next;
        }
        if(temp1!=NULL){
            head3->next = temp1;
        }
        if(temp2!=NULL){
            head3->next = temp2;
        }
        return merged->next;
    }
};
