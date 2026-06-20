//https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        if(digits[0]<9)
            digits[0]++;
        else{
            bool cont=true;
            int i=0;
            while(cont){
                digits[i] = 0;
                if(i+1>=digits.size())
                {
                    digits.push_back(1);
                    cont=false;
                }
                else{
                    if(digits[i+1] < 9){
                        digits[i+1]++;
                        cont=false;
                    }
                    else
                        i++;
                }
            }
        }
        reverse(digits.begin(), digits.end()); 
        return digits;
    }
};
