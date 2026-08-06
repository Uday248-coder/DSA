//https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

//TIME COMPLEXITY : O(N^2)
//SPACE COMPLEXITY : O(1)
// what if i first sort the array.. then choose one-element and run a two-pointer sum search for the rest length?
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++){
            int temp = target;
            temp -=arr[i];
            int l=i+1,r=arr.size()-1;
            while(l<r){
                if(temp-arr[l]-arr[r] ==0){
                    // cout << arr[i] <<" "<<arr[l] << " "<<arr[r] <<endl;
                    return true;
                }
                else if(temp - arr[l] < arr[r] )
                    r--;
                else if(temp - arr[r] >arr[l])
                    l++;
            }
        }
        return false;
    }
};
