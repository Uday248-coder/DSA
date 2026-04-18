//https://leetcode.com/problems/mirror-distance-of-an-integer/description/?envType=daily-question&envId=2026-04-18
class Solution {
    public int mirrorDistance(int x) {
        long temp=x, y=0;
        while(temp>0){
            y+=temp%10;
            y*=10;
            temp/=10;
        }
        y/=10;
        // System.out.println(x+" || "+y);
        return Math.abs((int)(x-y));

    }
}
