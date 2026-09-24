//https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/description/?envType=daily-question&envId=2026-09-24

//TC : O(N* log(N))
  
class Solution {
public:
    int digsum(int x){
        if(x<10)
            return x;
        int s=0;
        while(x>0){
            s+=x%10;
            x/=10;
        }
        return s;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if( i == digsum(nums[i]))
                return i;
        }
        return -1;
    }
};
