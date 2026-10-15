//https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1

class Solution {
  public:
    int lowercount(vector<vector<int>>& m, int val){
        int n=m.size();
        int ans = 0;
        int r=n-1, c=0;
        while(r>=0&& c<n){
            if(m[r][c]<=val){
                ans+=r+1;
                c++;
            }
            else{
                r--;
            }    
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // using binary search over answer pattern..
        int n=mat.size();
        int low = mat[0][0];
        int high = mat[n-1][n-1];
        int ans = high;
        while(low<=high){
            int middle = low + (high-low)/2;
            int count = lowercount(mat, middle);
            if(count >= k){ // earlier, count == middle would immedeatly send back the middle but without knowing whether that 'middle' element actully existed inside the matrix or not, this one, goes further below by enacting over smaller elements until none smaller are present
                ans = middle;
                high = middle-1;
            }
            else{
                low = middle+1;
            }
        }
        return ans;
    }
};
