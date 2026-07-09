//https://leetcode.com/problems/find-the-duplicate-number/description/
// MAIN CONSTRAINTS not to use extra space, not to modify the array.


// a solution that gives TLE : Linear seacrh.
class Solution {
    public int findDuplicate(int[] nums) {
        // since array size = n+1; intergeres from 1-n.. 
        // compare each element one by one.
        for(int i=0;i<nums.length-1;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i]==nums[j])
                    return nums[i];
            }
        }
        return nums[0];
    }
}



// Phase 1: Move slow by 1 step and fast by 2 steps until they meet inside the cycle.
// Phase 2: Reset slow to the start, then move both one step at a time.
// The point where they meet again is the cycle's entrance, which is the duplicate number.
// TC : O(N)
// SC : O(1)
class Solution {
    public int findDuplicate(int[] nums) {
       //floyd's algorithm.. No extra space used

       int slow=nums[0], fast=nums[nums[0]];
       while(nums[slow]!=nums[fast]){
        slow=nums[slow];
        fast=nums[nums[fast]];
       }
       slow=0;
       while(nums[slow]!=nums[fast]){
        slow=nums[slow];
        fast=nums[fast];
       }
    return nums[slow];
    }

}
