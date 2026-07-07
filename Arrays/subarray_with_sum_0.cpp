// https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
// tc : O(N)
// SC : O(N) -- unorderd map used right..

class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        /*My first approach is to convert the array into a prefix sum array. Once we have the prefix sums, there are two cases where a zero-sum subarray exists:

        1. If any prefix sum is `0`, then the subarray from index `0` to that index has a sum of `0`.
        2. If any prefix sum appears more than once (i.e., there are duplicate prefix sums), then the sum of the elements between those two indices must be `0`. This is because the repeated prefix sums cancel each other out when subtracted.
        So, after computing the prefix sums, I check for either a `0` prefix sum or duplicate prefix sums using a hash map. If either condition is true, a zero-sum subarray exists; otherwise, it does not.*/

        
        for(int i=1;i<arr.size();i++){
            arr[i]=arr[i]+arr[i-1];
        }
        unordered_map<int, int> map;
        for(int i:arr){
            map[i]+=1;
            if(i==0)
                return true;
        }
        // for(int i:arr)
        //     cout << i << endl;
        for(int i:arr){
            if(map[i]>1)
                return true;
        }
        return false;
    }
};
