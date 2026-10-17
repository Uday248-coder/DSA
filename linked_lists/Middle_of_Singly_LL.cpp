//https://leetcode.com/problems/middle-of-the-linked-list/submissions/2174298092/

//Slow and Fast Pointer Approach Tha
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow =head;
        ListNode* fast =head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};




// Brute-Force Approach Tha
// TC: O(N + N/2) 
// SC: O(1), i think so :)


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
    ListNode* middleNode(ListNode* head) {
        //brute-force
        int size=0;
        ListNode* x=head;
        while(x!=NULL){
            size++;
            x=x->next;
        }
        x=head;
        size = ((size/2) +1);
        while(--size)
            x=x->next;
        return x;
    }
};
