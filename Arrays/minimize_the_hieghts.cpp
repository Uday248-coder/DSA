//https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1
class Solution {
  public:
    
    int getMinDiff(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int ans=arr[arr.size()-1]-arr[0];
        int small = arr[0]+k;
        int large = arr[arr.size()-1]-k;
        int mini, maxi;
        for(int i=0;i<arr.size();i++){
            mini=min(small,arr[i+1]-k);
            maxi=max(large,arr[i]+k);
            if(mini<0)
                continue;
            ans=min(ans, maxi-mini);
        }
        return ans;
    }
};
