// https://www.geeksforgeeks.org/problems/maximum-difference-between-pair-in-a-matrix/1


// this is my current understanding of the question
// how ever i just got the insight that this problem wants me to find the maxi of the left-over elements that are in the region present to the down-right of the curr element, and then return the max of that..
// will implement it as well.
class Solution {
  public:
    int findMaxValue(vector<vector<int>>& mat) {
        // code here
        int maxi = mat[0][0] - mat[1][1];
        for(int i=1;i<mat.size();i++){
            for(int j=1;j<mat.size();j++){
                maxi = max(maxi , mat[i][j] - mat[i-1][j-1]);
            }
        }
        return maxi;
    }
};
