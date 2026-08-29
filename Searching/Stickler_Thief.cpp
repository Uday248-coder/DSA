//https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1


class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // we shall use DP over here.. 
        // we shall see the best outocme if we take or leave it..
        int n=arr.size();
        vector<int> dp(arr.size());
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<arr.size();i++){
            dp[i] = max(dp[i-2]+arr[i], dp[i-1]);
        }
        return dp[dp.size()-1];
    }
};
