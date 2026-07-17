//https://www.geeksforgeeks.org/problems/count-element-occurences/1

class Solution {
  public:
    int countOccurence(vector<int>& arr, int k) {
        int count=0;
        int rep = arr.size() / k +1 ;
        unordered_map<int,int> freq;
        for(int i:arr){
            freq[i]++;
        }
        for(auto& [k,v]: freq){
            if(v >=rep)
                count++;
        }
        return count;
    }
};
