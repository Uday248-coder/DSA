// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// TC : O(N^2)
// SC : O(N)
// wrong approach right now 
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int dis=arr.size();
        int i=0;
        int count=0;
        while(dis>0){
            cout << arr[i] << endl;
            count++;
            if(arr[i]==0){
                return -1;
            }
            else{
                int maxi=arr[arr[i]+1];
                int new_i = arr[i];
                for(int j=1;j<=arr[i];i++){
                    if(maxi < arr[j+arr[i]]){
                        maxi = arr[j+arr[i]];
                        new_i = j+arr[i];
                    }
                }
                i=new_i;
                dis-=maxi;
            }
            
            if(dis<=0){
                return count;
            }
        }
    }
};
