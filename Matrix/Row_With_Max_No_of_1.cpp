//https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1


class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int maxi = 0;
        int max_row = -1;
        
        for(int i=0;i<arr.size();i++){
            int sum=0;
            for(int j : arr[i]){
                sum+=j;
            }
            if(sum>maxi)
            {
                maxi=sum;
                max_row = i;
            }    
        }
        return max_row;
        
    }
};
