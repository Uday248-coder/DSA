package Sorting;

import java.util.Arrays;

public class Cycle_sort {

    public int findDuplicate(int[] a) {
        // Given an array with one element as a duplicate, find it
        int i = 0, len = a.length;
        int k = 1;
        while (i < len) {
            int cor = a[i];
            if (a[i] != a[cor]) {
                int temp = a[cor];
                a[cor] = a[i];
                a[i] = temp;
            } else {
                i++;
            }
            System.out.println("Pass " + k + " : " + Arrays.toString(a));
            k++;
        }
        for (i = 0; i < len; i++) {
            if (a[i] != i + 1) {
                return a[i];
            }
        }
        return -1;

    }


    public int missingNumber(int[] a) {
        //Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
        int i=0,n=a.length;
        while(i<n)
        {
            int cor = a[i];
            if(a[i]<n && a[i]!=a[cor])
            {
                int temp=a[i];
                a[i]=a[cor];
                a[cor]=temp;
            }
            else
            {
                i++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(i!=a[i])
                return i;
        }
        return n;
    }
    public static void main(String[] args) {
        int a[]={3,5,2,1,4};
        int i=0,s=0,n=a.length;
        while(i<n)
        {
            int correct = a[i]-1;
            if(a[i]!=a[correct])
            {
                int temp=a[i];
                a[i]=a[correct];
                a[correct]=temp;
                s++;
            }
            else
            {
                i++;
                s++;
            }
        }
        System.out.println(Arrays.toString(a));
        System.out.println("Number of passes: "+s);

    }
}
