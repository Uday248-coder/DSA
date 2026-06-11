//https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[i]++;
            if(freq[i]>1)
                return true;
        }
        return false;
    }
};
