// https://www.geeksforgeeks.org/problems/sorted-matrix2333/1

// Brute Force
class Solution {
  public:
    vector<vector<int>> sortedMatrix(vector<vector<int>>& mat) {
        vector<int> ele;
        int n=mat.size(), m=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ele.push_back(mat[i][j]);
            }
        }
        sort(ele.begin(),ele.end());
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j] = ele[k++];
            }
        }
        return mat;
    }
};


