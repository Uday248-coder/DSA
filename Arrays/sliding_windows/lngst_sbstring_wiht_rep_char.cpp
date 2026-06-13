//https://leetcode.com/problems/longest-substring-without-repeating-characters/
// brute force approach, doesnt work yet
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // i think we'll start a window counter and increase the winodw and store the enteries in a freq order if the freq doesnt match then we resize the window
        int maxi=0;
        unordered_map<char,int> freq;
        int l=0, r=0;
        while(r<s.size()){
            freq[s[r]]++;
            if(freq.size() != r-l+1){
                maxi = max(maxi,freq.size());
                freq[s[l]]--;
                if(freq[s[l]]==0)
                    freq.erase(s[l]);
                l++;
            }
            r++;
        }
        return maxi; 
    }
};
