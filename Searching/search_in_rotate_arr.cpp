// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/2110922523/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // i can apply binary search.. on the two halfs.. 
        // first finding the rotation point, then i'll binary search over both halfs.
        int brk=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                brk=i;
                break;
            }
        }
        int l=0, h=brk;
        while(l<=h){
            int m=l + (h-l)/2;
            if(nums[m]==target)
                return m;
            else if(nums[m]>target)
                h=m-1;
            else
                l=m+1;
        }
        l=brk+1, h=nums.size()-1;
        while(l<=h){
            int m=l + (h-l)/2;
            if(nums[m]==target)
                return m;
            else if(nums[m]>target)
                h=m-1;
            else
                l=m+1;
        }
        return -1;
    }
};
