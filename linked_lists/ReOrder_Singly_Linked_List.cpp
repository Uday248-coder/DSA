//https://leetcode.com/problems/reorder-list/

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
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        // my plan is the split the ll into 0 to middle and middle to end, then reverse the second one, then either stitch them one after the other in either of the two or make a new dummy and start adding nodes alternatively.
        if(head->next==NULL){
            return;
        }
        ListNode* temp = head;
        ListNode* middle = head;
        ListNode* prev=NULL;
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next->next;
            prev = middle;
            middle=middle->next;
        }
        prev->next=NULL;
        middle = reverse(middle);
         temp= head;
        ListNode* head3 = new ListNode(0);
        ListNode* dummy = head3;
        while(middle!=NULL && temp!=NULL){
            head3->next = temp;
            temp=temp->next;
            head3=head3->next;
            head3->next=middle;
            middle=middle->next;
            head3=head3->next;
        }
        if(middle!=NULL)
            head3->next = middle;
        if(temp!=NULL)
            head3->next = temp;
        head = dummy->next;
    }
};
