//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int s=0; s<=n-m;s++){
            int j=0;
            while( j<m && haystack[s+j]==needle[j]){
                j++;
            }
            if(j==m){
                return s;
            }
        }
        return -1;
    }
};
