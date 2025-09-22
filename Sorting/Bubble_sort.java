package Sorting;
import java.util.*;

public class Bubble_sort {
    public static void main(String[] args) {
        int a[]={10,5,1,0,-1};
        // int b[]={1,2,3,4,5};
        int n=a.length;
        boolean flag=false;
        System.out.println("Pre-Sorting : "+Arrays.toString(a));
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    flag=true;
                }
            }
            System.out.println("Iteration "+(i+1)+" : "+Arrays.toString(a));
            if(!flag)
                break; 
        }
        System.out.println(Arrays.toString(a));
    }
}
