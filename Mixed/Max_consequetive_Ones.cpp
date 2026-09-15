//https://leetcode.com/problems/max-consecutive-ones-iii/

// optimal solution i believe
// basically l and r point to 0th index first.. 
//then we expand r.. 
//while we encounter any zero.. 
//we increment z count.. 
//if z count exceeds the number of 0's we can flip then we start moving our l 
//until the window of l and r fit within the required range of allowed zero flips
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int zcount=0;
        int maxi=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0){
                zcount++;
            }
            while(zcount>k){
                if(nums[l]==0){
                    zcount--;
                }
                l++;
            }
            maxi = max(maxi, r-l+1);
        }
        return maxi;
    }
};




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
