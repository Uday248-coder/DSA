//https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum--150253/1
// Time Complexity: O(N)
// Space Complexity: O(N)
// used hashmap to efficiently search and retrieve the complement (target - current) element.
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int,int> map;
        int count=0; // will give the count of pairs.
        for(int i:arr){
            int comp = target - i; // standing at element we'll check if its complement has been found so far or not
            if(map.find(comp) != map.end()){ // complement checking condition
                count += map[comp]; // freq of compliment is added so it will be counted for pair once
            }
            map[i]++; // incrementing the freq.
        }
        return count;
        
    }
};
