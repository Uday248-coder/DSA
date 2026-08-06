//https://leetcode.com/problems/smallest-divisible-digit-product-i/?envType=daily-question&envId=2026-08-06
class Solution {
public:
    int digitprod(int n){
        if(n==1 || n<10)
            return n;
        return (n%10)*digitprod(n/10); 
    }
    int smallestNumber(int n, int t) {
        for(int i=n;;i++){
            int p = digitprod(i);
            if(p%t ==0)
                return i;
        }
        return -1;
    }
};
