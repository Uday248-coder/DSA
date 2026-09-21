//https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

// TC: O(n* log(n))
// SC: O(1)

// optimal approach i beleive-- used binary search exactly like book allocation problem.
class Solution {
    int allocate(vector<int>& arr, int cap){
        int painter=1;
        int currsum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+currsum <= cap){
                currsum+=arr[i];
            }else{
                currsum=arr[i];
                painter++;
            }
        }
        return painter;
    }
  
  
  public:
   int minTime(vector<int>& arr, int k) {
        //using same binary search approach
        long long l=arr[0];
        long long h=0;
        for(int i:arr){
            h+=i;
            if(i>l){
                l=i;
            }
        }
        while(l<=h){
            long long m=(h+l)/2;
            if(allocate(arr,m) <= k){
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};
