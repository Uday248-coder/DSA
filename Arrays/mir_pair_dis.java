//https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/?envType=daily-question&envId=2026-04-17

// ITS O(n^2) make it O(n) or O(nlogn) to run...
class Solution {
    int reverse(int n){
        int x = 0;
        while(n>0){
            x+=n%10;
            x*=10;
            n/=10;
        }
        return x/10;
    }
    public int minMirrorPairDistance(int[] nums) {
        int n=nums.length;
        int ans = n+10;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(reverse(nums[i]) == nums[j]){
                    int a=Math.abs(i-j);
                    ans = Math.min(ans, a);
                }
            }
        }
        return (ans == n+10)?-1:ans;
    }
}
