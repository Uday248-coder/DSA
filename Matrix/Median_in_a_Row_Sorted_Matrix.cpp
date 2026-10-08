//https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1


// Brute-Force Solution
// TC: O(N^2)
// SC: O(N)
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int> ele;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ele.push_back(mat[i][j]);
            }
        }
        sort(ele.begin(),ele.end());
        return ele[ele.size()/2];
    }
};
