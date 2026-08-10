// Chinese Remainder Theorem..

import java.util.*;
class CRT{
    public static int finder(int[] rem, int[] div, int size){
        int x=1;
        while(true){
            int j;
            for(j=0;j<size;j++){
                if(x%div[j] != rem[j])
                    break;
            }
            if(j==size) // all modulos passed
                return x;
            x++; // update x and re-start.
        }
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);     
        System.out.println("Enter the number of congruence relations: ");
        int size = sc.nextInt();      
        int a[] = new int[size];
        int m[] = new int[size];
        System.out.println("Enter the values of a: ");
        for (int i = 0; i < size; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println("Enter the values of m: ");
        for (int i = 0; i < size; i++) {
            m[i] = sc.nextInt();
        }
        System.out.println("x is " + finder(a, m, size));
    }

}
