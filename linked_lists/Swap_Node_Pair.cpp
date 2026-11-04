//https://leetcode.com/problems/swap-nodes-in-pairs/
// TC: O(N)
// SC: O(N/2)

// Using Recursion
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next==NULL)
            return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = swapPairs(second->next);
        second->next = first;
        head = second;
        return head;
    }
};

// Brute-Forced using iteration might be more optimisable and the logic viewing is kinda scary here, i am getting confused myself
//  TC : O(N)
//  SC : O(1)

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next==NULL)
            return head;
        ListNode* Prev = new ListNode(0);
        Prev->next = head;
        head = Prev;
        while(Prev->next!=NULL && Prev->next->next!=NULL){
            ListNode* first = Prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            Prev->next = second;
            Prev = first;
        }
        return head->next;
    }
};
 
