//https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
class Solution {
    public static int smallestSubWithSum(int x, int[] arr) {
        int l=0;
        int sum=0;
        int mini=arr.length+1;
        for(int r=0;r<arr.length;r++){
            sum+=arr[r];
            while(sum>x){
                mini=Math.min(mini, r-l+1);
                sum-=arr[l];
                l++;
            }
        }
        return mini == arr.length + 1 ? 0 : mini;
        
    }
}
