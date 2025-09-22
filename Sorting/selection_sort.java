package Sorting;

import java.util.Arrays;

public class selection_sort {
    public static void main(String[] args) {
        int a[]={10,5,1,0,-1};
        // int b[]={1,2,3,4,5};
        int n=a.length;
        // boolean flag;
        System.out.println("Pre-Sorting : "+Arrays.toString(a));
        for(int i=0;i<n;i++)
        {
            // flag=false;
            int max=0;
            for(int j=0;j<n-i;j++)
            {
                if(a[max]<a[j])
                {
                    max=j;
                    // flag=true;
                }
            }
            System.out.println("Iteration "+(i+1)+" : "+Arrays.toString(a));
            // if(!flag){
            //     break;
            // }
            int temp=a[max];
            a[max]=a[n-i-1];
            a[n-i-1]= temp;
        }
        System.out.println(Arrays.toString(a));
        // sc.close();
    }
}
