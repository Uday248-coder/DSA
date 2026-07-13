//https://www.geeksforgeeks.org/problems/find-position-of-set-bit3706/1
class Solution {
  public:
    int findPosition(int n) {
        float power = log2(n);
        
        if(n==0 || n%2!=0 || power!=floor(power))
            return -1;
        return (int)(floor(power+1));
    }
};
