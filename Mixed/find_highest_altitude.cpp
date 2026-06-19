//https://leetcode.com/problems/find-the-highest-altitude/?envType=daily-question&envId=2026-06-19
// Time Complexity : O(N) - does in single pass
// Space Complexity : O(1)

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=max(gain[0],0);
        for(int i=1;i<gain.size();i++){
            gain[i]=gain[i]+gain[i-1];
            maxi = max(maxi, gain[i]);
        }
        return maxi;
    }
};
