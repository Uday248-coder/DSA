//https://www.geeksforgeeks.org/problems/minimum-swaps/1
// TC: O(N log N)
// SC: O(N)
class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        vector<pair<int,int>> map;
        for(int i=0;i<arr.size();i++){
            map.push_back({arr[i],i});
        }
        sort(map.begin(),map.end());
        int count=0;
        for(int i=0;i<arr.size();i++){
            pair<int,int> p=map[i];
            while(p.second!=i){
                swap(map[i], map[p.second]);
                p=map[i];
                count++;
            }
        }
        return count;
    }
};
