//https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// optimal approach -> using binary search


// brute-forced -> works for k=2 by checking manual splits.. but gotta be better here now..
class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        if(arr.size()<k){
            return -1;
        }
        else if(arr.size()==k){
            int min=arr[0];
            for(int i:arr){
                if(min>i){
                    min=i;
                }
            }
            return min;
        }
        vector<int> pref;
        pref.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            pref.push_back(arr[i]+pref.back());
        }
        int r=pref.size()-1;
        int l=0;
        vector<int> stored_ans;
        while(l<r){
            int x =max(pref[l] , pref[r] - pref[l]);
            stored_ans.push_back(x);
            l++;
        }
        int min=stored_ans[0];
        for(int i:stored_ans){
            if(min>i){
                min=i;
            }
        }
        return min;
    }
};
