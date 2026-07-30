//https://leetcode.com/problems/next-permutation/

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end()); // It operates strictly with a space complexity of O(1)
        }else{
        for(int i=nums.size()-1;i>=ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end()); // It operates strictly with a space complexity of O(1)
        }
    }
};
