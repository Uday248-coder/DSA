//https://www.geeksforgeeks.org/problems/palindrome-numbers0942/1

class Solution {
    
    public boolean isBinaryPalindrome(int n) {
        String m = Integer.toBinaryString(n);
        int l = m.length();
        for(int i=0; i<l/2;i++){
            if(m.charAt(i)!=m.charAt(l-i-1))
                return false;
        }
        return true;
        
    }
};
