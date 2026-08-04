//https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
//TC: O(N)
//SC: O(N)
class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int,int> freq;
        for(int i:a){
            freq[i]++;
        }
        for(int i:b){
            if(freq[i]==0){
                return false;
            }
            else{
                freq[i]--;
            }
        }
        return true;
        
    }
};
