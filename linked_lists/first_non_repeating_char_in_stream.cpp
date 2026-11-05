//https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// TC: O(N)
// SC: O(N)

class Solution {
  public:
    string firstNonRepeating(string &s) {
        queue<char> q;
        int freq[26] = {0};
        string ans = "";
        for(char c: s){
            q.push(c);
            freq[(int)(c - 'a')]++;
            while(!q.empty() && freq[(int)(q.front() - 'a')]>1){
                q.pop();
            }
            if(q.empty())
                ans.push_back('#');
            else
                ans.push_back(q.front());
        }
        return ans;
    }
};
