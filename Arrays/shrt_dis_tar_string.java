//https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=daily-question&envId=2026-04-15
class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        int n=words.length;
        int ans = n+10;
        for(int i=0;i<n;i++){
            if(words[i].equals(target)){
                int a=Math.abs(startIndex-i);
                int b = n - a;
                int curr = Math.min(a, b);
                ans = Math.min(ans, curr);
            }
        }
        return (ans == n+10)?-1:ans;
   }
}
