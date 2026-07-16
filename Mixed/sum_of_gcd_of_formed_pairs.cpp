//https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/?envType=daily-question&envId=2026-07-16

// SPACE : O(N)
// TIME : O(N logN)

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans =0 ;
        int maxi=nums[0];
        vector<int> temp; //O(N) space
        for(int i:nums){ // O(N) time
            maxi=max(maxi,i);
            temp.push_back(gcd(i,maxi));
        }
        sort(temp.begin(),temp.end()); //O(NlogN) time
        int n=temp.size();
        for(int i=0;i<n/2;i++){
            ans+=gcd(temp[i],temp[n-i-1]);
        }
        return ans;
    }
};
