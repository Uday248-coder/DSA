//https://leetcode.com/problems/squares-of-a-sorted-array/
// TC : O(N+M)
// SC : O(N)
//i made it faster idk..
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(pow(nums[i],2));
        }
        int l=0, r=nums.size()-1;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(temp[l]>temp[r]){
                nums[i]=temp[l];
                l++;
            }
            else{
                nums[i]=temp[r];
                r--;
            }
        }
        return nums;
    }
};
