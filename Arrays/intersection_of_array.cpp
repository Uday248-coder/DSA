//https://leetcode.com/problems/intersection-of-two-arrays/description/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> map;
        vector<int> ans;
        for(int i:nums1){
            map[i]=false;
        }
        for(int i:nums2){
            if(map.contains(i)){
                if(!map[i]){
                    ans.push_back(i);
                    map[i]=true;
                }
            }
        }
        return ans;
    }
};
