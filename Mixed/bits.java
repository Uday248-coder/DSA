//https://www.geeksforgeeks.org/problems/check-set-bits5408/1
class Solution {
    public boolean isBitSet(int n) {
        if(n==0)
            return false;
        if(n==1)
            return true;
        double y = Math.log(n+1) / Math.log(2);
        if( y == (int)y)
            return true;
        return false;
    }
};
