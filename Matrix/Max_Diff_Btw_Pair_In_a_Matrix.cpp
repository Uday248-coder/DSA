// https://www.geeksforgeeks.org/problems/maximum-difference-between-pair-in-a-matrix/1

// this is my best understanding so far....
class Solution {
  public:
    int findMaxValue(vector<vector<int>>& mat) {
        int n=mat.size();
        // making a suffix maxiimum matrix that stores the maximum element found for any sub-rectangle;
        int maxi = mat[n-1][n-1];
        vector<vector<int>> suffmaxi(n, vector<int>(n,0));
        for(int k=0;k<n-1;k++){
            suffmaxi[n-1][k] = 0;
            suffmaxi[k][n-1] = 0;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                maxi = max(maxi, mat[i+1][j+1]);
                suffmaxi[i][j] = maxi;
            }
            
        }
        int ans = mat[n-1][n-1] - mat[0][0];
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                ans = max(suffmaxi[i][j]-mat[i][j], ans);
            }
        }
        return ans;
    }
};
