//https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> map;
        while(true){
            int dig=0;
            map[n]++;
            while(n>0){
                dig += pow(n%10 , 2);
                n/=10;
            }
            if(dig == 1)
                return true;
            else if(map[dig]>0)
                return false;
            else{
                map[dig]++;
                n=dig;
            }
        }
    }
};
