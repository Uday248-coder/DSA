package Sorting;

import java.util.Arrays;

public class Insertion_sort {
    public static void main(String[] args) {
        int a[]={7,2,5,1,6};
        int n=a.length;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j>0;j--)
            {
                if(a[j]<a[j-1]){
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;}
                else{
                    break;
                }
            }
        }
        System.out.println(Arrays.toString(a));
    }
}
