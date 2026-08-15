//https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/?envType=daily-question&envId=2026-08-15

// brute force..
// i am failing somewhere, maybe i misread the question's intentions.
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int maxi=0;
        int xored=nums[0];
        int cnt=1;
        cout << nums[0] << " ";
        for(int i=1;i<nums.size();i++){
            if((nums[i]^xored) == 0){
                maxi = max(cnt,maxi);
                xored = nums[i];
                cnt=1;
            }else{
                cout << nums[i] << " "; 
                cnt++;
                xored^=nums[i];
            }
        }
        maxi=max(cnt,maxi);
        return maxi;
    }
};
