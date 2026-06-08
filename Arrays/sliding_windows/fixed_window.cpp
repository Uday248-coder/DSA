//https://leetcode.com/problems/maximum-average-subarray-i/
// wrong solution so far.
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0, r=k;
        double max=-999999;
        double sum=0;
        for(int i=0;i<nums.size() && r<nums.size();i++){
            if(i<r)
                sum+=nums.at(i);
            else
                sum = sum + nums.at(r++) - nums.at(l++);
            if(max < sum/k)
                max = sum/k;
        }
        
        return max;
    }
};
