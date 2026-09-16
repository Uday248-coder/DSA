//https://leetcode.com/problems/search-in-rotated-sorted-array/
// TC : O(logN)
// SC : O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid = l  + (r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else
                r=mid;
        }
        int p=l;
        if(target < nums[nums.size()-1]){
            l=p;
            r=nums.size()-1;
        }
        else if(target == nums[nums.size()-1]){
            return nums.size()-1;
        }
        else{
            l=0;
            r=p-1;
        }
        while(l<=r){
            int m=l + (r-l)/2;
            if(nums[m]==target)
                return m;
            else if(nums[m]>target)
                r=m-1;
            else
                l=m+1;
        }
        return -1;
    }
};
