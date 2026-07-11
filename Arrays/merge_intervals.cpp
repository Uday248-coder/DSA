// https://leetcode.com/problems/merge-intervals/

// TC : O(Nlogn) + O(2N)
// SC : O(N^2) 

//striver's brute force, worked with the same logic, coding in cpp is much more simple.. 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()); //O(NlogN)
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(!ans.empty() && end<=ans.back()[1]){
                continue;
            }
            for(int j=i+1;j<intervals.size();j++){
                if(intervals[j][0]<=end){
                    end= max(end, intervals[j][1]);
                }
                else{
                    break;
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};
