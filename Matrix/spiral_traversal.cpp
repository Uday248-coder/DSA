// https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int top=0;
        int bottom = mat.size()-1;
        int left =0;
        int right=mat[0].size()-1;
        vector<int> an;
        int i=0;
        while(top<=bottom && left<=right){
            for(i=left; i<=right;i++)
                an.push_back(mat[top][i]);
            top++;
            for(i=top; i<=bottom;i++)
                an.push_back(mat[i][right]);
            right--;
            if (top <= bottom) {
            for(i=right; i>=left;i--)
                an.push_back(mat[bottom][i]);
            bottom--;
            }
            if (left <= right) {
            for(i=bottom; i>=top;i--)
                an.push_back(mat[i][left]);
            left++;
            }
        }
        return an;
    }
};
