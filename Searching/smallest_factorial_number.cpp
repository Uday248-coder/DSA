//https://www.geeksforgeeks.org/problems/smallest-factorial-number5929/1


class Solution {
  public:
    long long trailing(long long n){
        long long zeros=0;
        while(n>=5){
            zeros +=n/5;
            n=n/5;
        }
        return zeros;
    }
    int findNum(int n) {
        long long l = 1;
        long long h = 5*n;
        int ans = h;
        while(l<=h){
            long long mid=l + (h-l)/2;
            if (trailing((long long)mid) >= (long long)n) {
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
