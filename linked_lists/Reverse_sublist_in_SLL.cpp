//https://leetcode.com/problems/reverse-linked-list-ii/

// TC: O(N)
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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* before = &dummy;
        ListNode* start;
        ListNode* end;
        ListNode* after;
        
        for(int i=1;i<left;i++){
            before=before->next;
        }
        start = before->next;
        end = start;
        for(int i=left;i<right;i++){
            end=end->next;
        }
        after=end->next;
        end->next=NULL;

        before->next = reverse(start);
        start->next = after;
        return dummy.next;
    }
};
