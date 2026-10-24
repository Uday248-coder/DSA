// https://leetcode.com/problems/longest-common-subsequence/

// TC : O(n*m)
// SC : O(n+1 * m+1)

class Solution {
    public int longestCommonSubsequence(String a, String b) {
        int dp[][]=new int[a.length()+1][b.length()+1];
        for(int i=0;i<a.length();i++){
            dp[i][0]=0;
        }
        for(int j=0;j<b.length();j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=a.length();i++){
            for(int j=1;j<=b.length();j++){
                if(a.charAt(i-1) == b.charAt(j-1)){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[a.length()][b.length()];
    }
}
