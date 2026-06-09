//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

//brute force approach
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        int sum = 0;
        int maxi = 0;
        bool mov = false;
        for (int i = 0; i < nums.size(); i++) {
            
            if (i < k){
                check[nums[i]]++;
                sum += nums[i];
            }
            else{
                mov =true;
                check[nums[i]]++;
                check[nums[i-k]]--;

                sum = sum + nums[i] - nums[i-k];
            }
            if(check[nums[i]] > 1)
                mov=false;
            if(mov)
                maxi = max(maxi,sum);
        }
        return maxi;
    }
};
