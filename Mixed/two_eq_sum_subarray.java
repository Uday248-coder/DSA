//https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1

class Solution {
    public boolean canSplit(int arr[]) {
        if(arr.length < 2)
            return false;
        for(int i=1;i<arr.length;i++){
            arr[i]+=arr[i-1];
        }
        
        for(int i=0;i<arr.length-1;i++){
            int a = arr[i];
            int b = arr[arr.length-1] - a;
            if(a == b)
                return true;
        }
        return false;
        
    }
}
