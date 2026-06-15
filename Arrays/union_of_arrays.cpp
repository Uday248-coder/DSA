//https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_map<int,bool> mapi;
        vector<int> res;
        for(int i:a)
            mapi[i]=true;
        for(int i:b)
            mapi[i]=true;
        for(auto& p: mapi)
            res.push_back(p.first);
        return res;
    }
};
