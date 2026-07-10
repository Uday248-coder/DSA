//https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// TC: O(N)
// SC: O(1)
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // // do we play with max here?
        // // i feel like whenever we reach array end or maxi is updated we find the abs diff* with the distance and subtract the data bloacks from between.
        // int last_max=0, maxi=arr[0];
        // int water=0, rsum=0;
        // for(int i=0;i<arr.size();i++){
        //     rsum+=arr[i];
        //     if(maxi < arr[i] or i==arr.size()-1){
                
                
        //         int stored = min(arr[i],arr[last_max])*abs(i-last_max-1);
        //         water = water + (stored - (rsum-arr[last_max] - arr[i]));
                
        //         // cout << maxi << " maxi" << endl;
        //         // cout << last_max << " last_max" << endl;
        //         // cout << arr[i] << " curr element" << endl;
        //         // cout << i << " at index" <<endl;
        //         // cout << stored << " water stored in this gap" << endl;
        //         // cout << water << " total" <<endl <<endl;
        //         last_max=i;
        //         rsum=0;
        //         maxi = arr[i];
        //     }
        // }
        // return water;

        // two pointer approach
        int left=0, right=arr.size()-1;
        int left_max=0, right_max=0;
        int water=0;
        while(left<=right){
            if(left_max<right_max){
            left_max=max(left_max,arr[left]);
            water = water + (left_max-arr[left]) ;
                left++;
            }else{
            right_max=max(right_max, arr[right]);
            water = water + (right_max-arr[right]);
                right--;
            }
            
        }
        return water;
    }
};
