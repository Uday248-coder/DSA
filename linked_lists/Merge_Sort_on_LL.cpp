//https://www.geeksforgeeks.org/problems/sort-a-linked-list/1

// TC : O(N LOG N)
// SC: O(N)
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
  
    void merger(vector<Node*>& arr, int left, int mid, int high){
        vector<Node*> temp;
        int i=left, j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i]->data<=arr[j]->data){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        for(int t=0;t<temp.size();t++){
            arr[left + t] = temp[t];
        }
    }
    
    void Mergesort(vector<Node*>& arr, int left, int right){
        if(left>=right)
            return;        
        int mid = (left+right)/2;
        Mergesort(arr,left,mid);
        Mergesort(arr,mid+1,right);
        merger(arr, left, mid, right);
    }
    Node* mergeSort(Node* head) {
        if(!head || !head->next)
            return head;
        vector<Node*> arr;
        for(Node* t=head; t; t=t->next){
            arr.push_back(t);
        }
        Mergesort(arr, 0, (int)(arr.size() - 1));
        head = arr[0];
        Node* temp = head;
        for(int i=1;i<arr.size();i++){
            temp->next=arr[i];
            temp=temp->next;
        }
        temp->next=NULL;
        return head;
    }
};
