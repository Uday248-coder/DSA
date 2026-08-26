//https://practice.geeksforgeeks.org/problems/find-pair-given-difference/0


// two pointer run.. on sorted array?
// brute force -- implementation failure..

class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        sort(arr.begin(),arr.end());
        int l=0, r=arr.size()-1;
        while(r>0){
            int diff = arr[r]-x;
            while(diff>arr[l] && l<arr.size()){
                l++;
            }
            if(l>=arr.size() || diff!=arr[l]){
                r--;
                l=0;
            }else{
                return true;
            }
        }
        return false;
    }
};


// acutal code

class Solution {
  public:
    bool findPair(vector<int>& arr, int x) {
         sort(arr.begin(), arr.end());
         int i = 0, j = 1;
         while (j < arr.size()) {
             int diff = arr[j] - arr[i];
             if (diff == x)
                 return true;
             if (diff < x)
                 j++;
             else
                 i++;
             if (i == j)
                 j++;
         }
         return false;
     }
};
