//https://leetcode.com/problems/maximum-average-subarray-i/
// made use of the windows edge pointers(the sliding window)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        for(int i=0;i<k;i++)
            sum+=nums[i];
        double ans = sum;
        for(int i=k;i<nums.size();i++){
            sum = sum + nums[i] - nums[i-k];
            if( ans < sum )
                ans = sum;
        }
        return ans/k;
    }
};
