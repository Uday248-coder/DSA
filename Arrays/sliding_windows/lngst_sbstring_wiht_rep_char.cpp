//https://leetcode.com/problems/longest-substring-without-repeating-characters/
// updated version, has to learnt again

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // i think we'll start a window counter and increase the winodw and store the enteries in a freq order if the freq doesnt match then we resize the window
        int maxi=0;
        unordered_map<char,int> freq;
        int l=0,r=0;
        while(r<s.size()){
            if(freq.contains(s[r]) && freq[s[r]] >= l)
                l= freq[s[r]] + 1;    
            freq[s[r]] = r;
            maxi = max(maxi, r-l+1);
            r++;
        }


        return maxi; 
    }
};
