//https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// TC : O(n*W)
// SC : O(n*W)

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size(); // number of items..
        vector<vector<int>> dp(n+1, vector<int>(W+1,0));
        
        for(int i=1;i<=n;i++){
            for(int w=1;w<=W;w++){
                
                if(wt[i-1] <=w){  // if item i-1 fits into the current kanpsack capacity
                    dp[i][w]=max(dp[i-1][w], // leave it
                                val[i-1]+dp[i-1][w-wt[i-1]] // take it
                        );
                }
                else{
                    dp[i][w]=dp[i-1][w]; //leave it
                }
            }
        }
        // for(vector<int> a : dp){
        //     for(int i:a){
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n][W]; // give back the optimal value.
    }
};
