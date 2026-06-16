//https://leetcode.com/problems/move-zeroes/submissions/2034684561/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z=0, nz=0;
        while(nz<nums.size()){
            if(nums[z]!=0){
                z++;
                nz=z;
            }
            else{
                if(nums[nz]==0){
                    nz++;
                }
                else{
                    nums[z]=nums[nz];
                    nums[nz]=0;
                }
            }
        }
    }
};
