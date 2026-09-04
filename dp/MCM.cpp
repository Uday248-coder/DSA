//https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        if(arr.size()<3)
            return 0;
        int n=arr.size();
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size()));
        vector<vector<int>> split(arr.size(), vector<int>(arr.size()));
        
        for(int i=0;i<arr.size();i++){
            dp[i][i]=0;
        }
        
        for(int len=2;len<n;len++){
            for(int i=1;i<n-len+1;i++){
                int j= i+len-1;
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++){
                    int cost = dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[j]*arr[k]);
                    if(cost < dp[i][j]){
                        dp[i][j]=cost;
                        split[i][j]=k;
                    }
                }
            }
        }
        return dp[1][n-1];
    }
};
