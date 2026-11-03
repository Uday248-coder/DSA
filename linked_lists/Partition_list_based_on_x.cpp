//https://leetcode.com/problems/partition-list/

//TC: O(N)
//SC: O(1)

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* more = new ListNode(1);
        ListNode* tl=less; 
        ListNode* tm=more;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* next = temp->next;
            temp->next=NULL;
            if(temp->val < x){
                tl->next=temp;
                tl=tl->next;
            }
            else{
                tm->next=temp;
                tm=tm->next;
            }
            temp=next;
        }
        more=more->next;
        less=less->next;
        if(less==NULL){
            return more;
        }
        tl->next=more;
        return less; 
    }
};
