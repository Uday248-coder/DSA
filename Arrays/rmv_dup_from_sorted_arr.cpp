//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// time complexity -- O(n)
// space somplexity -- O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // i think i can make the two pointer approach by myself.
        int l=0;// it will store the pointer for the last distinct element found
        for(int i=1;i<nums.size();i++){ // our second pointer that shall iterate over array
            if(nums[i]!=nums[l]){ // if the iterator pointer finds a new element that is so far not discovered(since arr is sorted)
                nums[++l]=nums[i]; // we just overwrite the position and update the lastpointer to point to this newly discovered element
            }
        }
        return l+1; // we return the size by index + 1
    }
};
