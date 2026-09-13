// https://www.geeksforgeeks.org/problems/arithmetic-number2815/1
class Solution {
  public:
    int inSequence(int a, int b, int c) {
        // code here
        b=b-a;
        if((c==0 && b!=0) || (b%c !=0)){
            return false;
        }
        return true;
    }
};
