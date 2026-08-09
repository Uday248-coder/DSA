// a number is binary palindrome if their binary representation is same if read from left to right or right to left.

import java.util.*;
class Main {
    public static boolean Palindrome(int N){
        String s=Integer.toBinaryString(N);
        int i=0, j=s.length()-1;
        while(i<j){
            if(s.charAt(i) != s.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter Number to be checked: ");
        int x=sc.nextInt();
        System.out.println("Is the Number '"+x+"' a Binary Palindrome: "+Palindrome(x));
    }
}
