//https://leetcode.com/problems/move-zeroes/submissions/2034684561/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //optimizing it.
        int z=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                z=i;
                break;
            }
        }
        for(int i=z;i<nums.size();i++){
            if(nums[i]!=0){
                nums[z]=nums[i];
                nums[i]=0;
                z++;
            }
        }
    }
};
