//https://www.geeksforgeeks.org/problems/quick-sort-on-linked-list/1

// TC : O(N LogN)
// SC : O(N)

/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    int partition(vector<Node*>& arr, int low, int high){
        Node* pivot=arr[high];
        int i=low-1; 
        for(int j=low;j<high;j++){
            if(arr[j]->data < pivot->data){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
    }
    void quick(vector<Node*>& arr, int low, int high){
        if(low>=high)
            return;
        int p = partition(arr, low, high);
        quick(arr,low, p-1);
        quick(arr,p+1,high);
    }
    Node* quickSort(Node* head) {
        if(!head || !head->next)
            return head;
        vector<Node*> arr;
        for(Node* t=head; t; t=t->next){
            arr.push_back(t);
        }
        quick(arr,0,arr.size()-1);
        head=arr[0];
        Node* temp=head;
        for(int i=1;i<arr.size();i++){
            temp->next = arr[i];
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
    }
};
