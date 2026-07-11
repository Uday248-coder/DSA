// https://leetcode.com/problems/merge-intervals/

// TC : O(N)
// SC : O(N^2)

//brute force attempt, tried manually checking each interval and making sure it broke at uneven intervals but whatver..i'll learn and fix them
class Solution {
    public int[][] merge(int[][] intervals) {
        int[][] answers = new int[intervals.length][2];
        int mini=intervals[0][0];
        int maxi=intervals[0][1];
        int k=0;
        for(int[] i:intervals){
            System.out.println(i[0]+" "+i[1]);
            if(i[0]<mini && i[1]<=maxi){
                mini=i[0];
            }
            else if(i[0]<=maxi){
                maxi=Math.max(maxi,i[1]);
            }
            else if(i[0]>maxi){
                // System.out.println(mini+"  "+maxi+" ");
                answers[k][0]=mini;
                answers[k][1]=maxi;
                mini=i[0];
                maxi=i[1];
                k++;
            }
        }
        return answers;
    }
}
