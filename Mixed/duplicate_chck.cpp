//https://leetcode.com/problems/contains-duplicate/
// corrected my freq approach, its correct1
// but i believe not the optimal one...
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>1)
                return true;
        }
        return false;
    }
};
