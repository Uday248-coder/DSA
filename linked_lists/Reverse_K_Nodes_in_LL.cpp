//VARIANT 1-> //https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
//VARIANT 2-> //https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/2175903816/

// VARIANT 1 SOLUTION-> 
/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        int len=0;
        Node* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len<k){
            
            Node* curr=head;
            Node* prev=NULL;
            
            while(curr!=NULL){
                Node* next = curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
        Node* prev=NULL;
        Node* curr=head;
        for(int i=1;i<=k;i++){
            Node* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        Node* rem_list = reverseKGroup(curr, k);
        head->next=rem_list;
        return prev;
    }
};

//VARIANT 2 SOLUTION-> 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        if(len<k){
            return head;
        } 
        ListNode* curr=head;
        ListNode* prev=NULL;
        for(int i=1;i<=k;i++){
            ListNode* next =curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* rem_list = reverseKGroup(curr, k);
        head->next = rem_list;
        return prev;
    }
};
