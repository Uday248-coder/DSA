//https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=daily-question&envId=2026-06-14

// should i create two temp list, first points to the current head
// second one i'll make in such a way that i reverse the linked list in one pass, there by i would have two pointers one pointing to the head to the linked list and another pointiing to the opposite end off the linked list?
// but i fear that maybe i'll destroy the original linked list while reversing the linked list thereby i will end up in the same position of having only one directional approach.


/// orrr i just read stack somewhere, what if i make two stacks, traverse the linked list in one pass and store elements in first stack and create an idea about the length, then push out the length/2 elements into the second stack 
// that will leave me with two stacks and then it would be a matter of simply poping elements simpultaneously from both stack and adding and storing the max that occured! this seemes better






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
    int pairSum(ListNode* head) {
        
        
    }
};
