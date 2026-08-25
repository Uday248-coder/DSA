//https://www.geeksforgeeks.org/problems/majority-element-1587115620/1
// Moore's Voting Algorithm
// TC : O(N)
// SC : O(1)
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // moore's voting algorithm
        int ele=arr[0];
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(cnt == 0){
                ele =arr[i];
                cnt=1;
            }
            else if(ele == arr[i])
                cnt++;
            else
                cnt--;
        }
        //verifying that the element chosen was crossing the threshold or not..
        cnt=0;
        for(int i:arr){
            if(ele==i){
                cnt++;
            }
        }
        if(cnt > arr.size()/2)
            return ele;
        return -1;
    }
};
