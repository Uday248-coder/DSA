//https://leetcode.com/problems/weighted-word-mapping/?envType=daily-question&envId=2026-06-13
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string x:words){
            int sum=0;
            for(char c:x){
                sum+=weights[(int)c - 97];
            }
            sum%=26;
            ans = ans + (char)(122-(sum));
        }
        return ans;
    }
};
