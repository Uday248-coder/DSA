//https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

//TC: O(N^3)
//SC : O(1)

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        // should i apply two nested loop and then a two sum ?
        sort(arr.begin(),arr.end());
        vector<vector<int>> answer;
        for(int i=0;i<arr.size();i++){
            
            if (i > 0 && arr[i] == arr[i - 1]) continue; // skipping duplicates
            
            for(int j=i+1;j<arr.size();j++){
                
                if (j > i + 1 && arr[j] == arr[j - 1]) continue; // skipping duplicates
                
                int l = j+1, r=arr.size()-1;
                while(l<r){
                    if(arr[i]+arr[j]+arr[l]+arr[r] == target){
                        answer.push_back({arr[i],arr[j],arr[l],arr[r]});
                        
                        while (l < r && arr[l] == arr[l + 1]) l++; // skipping duplicates
                        while (l < r && arr[r] == arr[r - 1]) r--; // skipping duplicates
                        l++;
                        r--;
                        
                    }else if( arr[i]+arr[j]+arr[l]+arr[r] < target){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
            }
        }
        
        return answer;
    }
};
