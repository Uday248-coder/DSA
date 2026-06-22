//https://leetcode.com/problems/maximum-number-of-balloons/submissions/2042490195/?envType=daily-question&envId=2026-06-22
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0;
        for(char c:text){
            if(c=='l')
                l++;
            if(c=='o')
                o++;
            if(c=='b')
                b++;
            if(c=='a')
                a++;
            if(c=='n')
                n++;
            // cout << c << endl;
        }
        // cout << a << " " << b <<" "<<l<< " " << o<< " " << n<< " " << endl;
        if(a==0 || b==0 || l==0 || n==0 || o==0)
            return 0;
        int count =0;
        while(true){
            if(a-1 >=0 && b-1>=0 && l-2>=0 && o-2>=0 && n-1>=0){
                count++;
                a-=1;
                b-=1;
                o-=2;
                n-=1;
                l-=2;
            }
            else
                break;
        }
        return count;
    }
};
