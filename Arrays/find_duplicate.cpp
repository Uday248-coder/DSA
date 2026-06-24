//https://leetcode.com/problems/find-the-duplicate-number/submissions/2044946178/

//using hashmap
// TC : O(N)
// SC : O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]=true;
            if(map.size()!=i+1)
                return nums[i];
        }
        return 0;
    }
};

// one-pass..
// TC: O(N)
// SC : O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
                return nums[i];
        }
        return nums[0];
    }
};
