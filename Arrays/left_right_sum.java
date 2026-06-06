//https://leetcode.com/problems/left-and-right-sum-differences/?envType=daily-question&envId=2026-06-06
class Solution {
    public int[] leftRightDifference(int[] nums) {
        int n=nums.length;
        int l[] = new int[n];
        int r[]=new int[n];
        r[n-1]=0;
        l[0]=0;
        for(int i=1;i<n;i++){
            l[i]=nums[i-1]+l[i-1];
        }
        for(int i=n-2;i>=0;i--){
            r[i]=nums[i+1]+r[i+1];
        }
        // for(int i: r)  
        //     System.out.print(" "+i);
        // int ans[]=new int[n];
        for(int i=0;i<n;i++){
            nums[i]=Math.abs(l[i]-r[i]);
        }
        return nums;
    }
}
