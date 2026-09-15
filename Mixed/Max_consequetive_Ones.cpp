//https://leetcode.com/problems/max-consecutive-ones-iii/


//1st approach.. failed as i am missing overlaps.. will make some pointer adjustments to be better

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi=0;
        int count=0;
        int temp=k;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && temp==0){
                maxi = max(maxi,count);
                temp = k-1;
                count=1;
            }
            else{
                if(nums[i]==0)
                    temp--;
                count++;
            }
        }
        return maxi;
    }
};
