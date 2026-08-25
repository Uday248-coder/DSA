//https://www.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1
// expected TC: O(N)
// expected SC: O(1)

// brute approach -- > linear search
class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        for(int i=0;i<arr.size();i++)
        {
            if(x == arr[i])
                return i;
        }    
        return -1;
    }
};


//  a bit more optimal approach would be to utilise the K-Step Property of the array..
