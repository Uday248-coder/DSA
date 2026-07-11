// https://leetcode.com/problems/merge-intervals/

// TC : O(Nlogn) + O(N) === O(Nlogn)
// SC : O(N^2) 

//optimal solution. still unclear, gotta understand better and comeback to paste reasoning.
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()); //O(NlogN)
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(ans.empty() || arr[i][0]>ans.back()[1]){
                ans.push_back(arr[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
                
            }
        }
        return ans;
    }
};
