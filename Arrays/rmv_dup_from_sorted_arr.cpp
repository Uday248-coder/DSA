//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// this is raw approach.
class Solution {
public:
    // time complexity -- O(n)
    // space somplexity -- O(n)
    int removeDuplicates(vector<int>& nums) {
        // i can work around with hash maps right? jjust giving a try
        unordered_map<int, int> map;
        for(int i:nums)
            map[i]=i;
        int k=0;
        nums.clear();
        for(auto i:map)
            nums.push_back(i.first);
        sort(nums.begin(), nums.end());
        return map.size();
    }
};
