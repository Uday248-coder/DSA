//https://leetcode.com/problems/squares-of-a-sorted-array/
// TC : O(N+M)
// SC : O(N)
//its a better approach i made using two pointers. gotta find the best approach
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=pow(nums[i],2);
        }
        int l=0, r=nums.size()-1;
        vector<int> ans;
        while(l<=r){
            if(nums[l]>nums[r]){
                ans.insert(ans.begin() + 0, nums[l]);
                l++;
            }
            else{
                ans.insert(ans.begin() + 0, nums[r]);
                r--;
            }
        }
        return ans;
    }
};
