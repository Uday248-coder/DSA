//https://leetcode.com/problems/rotate-list/

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
    int len(ListNode* head){
        int count =0;
        while(head!=NULL){
            head=head->next;
            count++;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int size = len(head);
        // cout << size;
        if(k>=size)
            k=k%size;
        ListNode* newHead = head;
        ListNode* curr = head;
        for(int i=1;i<size-k;i++){
            curr=curr->next;
        }
        newHead = curr->next;
        curr->next=NULL; // removed the link from the original list to break the chains
        curr = newHead; // re-using pointer for a different purpose now
        if(curr==NULL)
            return head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next = head;
        return newHead;
    }
};
