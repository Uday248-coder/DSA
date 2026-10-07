//https://leetcode.com/problems/search-a-2d-matrix/

// TC : O(log(n) + log(m)) <-- Binary Searching for the correct row, when we find the correct row, then we binary search in it to find the target element. 
// SC : O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l=0, h=rows-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][cols-1]){
                int lower = 0, higher = cols-1;
                while(lower<=higher){
                    int middle = lower + (higher-lower)/2;
                    if(target == matrix[mid][middle])
                        return true;
                    else if(target < matrix[mid][middle]){
                        higher = middle-1;
                    }
                    else{
                        lower = middle +1;
                    }
                }
                break;
            }
            else if(target < matrix[mid][0]){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return false;
    }
};
