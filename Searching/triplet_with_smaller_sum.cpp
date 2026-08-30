//https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

// TC : O(N^2)
// SC : O(1)

// we could have sorted the array for the best two-pointer count stratergy.. hence used it.. 
class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int count = 0;
        for(int i=0;i<arr.size();i++)
        {
            int l=i+1, r=arr.size()-1;
            while(l<r){
                if(arr[i]+arr[l]+arr[r] < sum){
                    count += (r-l);
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return count;
    }
};
