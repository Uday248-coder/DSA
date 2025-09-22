package Searching;
import java.util.*;
public class binary_search_2d {

    int[] binary_search(int[][] arr,int target, int lb,int ub,int r){
        // used in sorted matrix 
        //-- mainly to do binary search on provided row and the limits
        while(lb<=ub)
        {
            int mid=lb + (ub-lb)/2;
            if(arr[r][mid]==target)
                return new int[]{r,mid};
            else if(arr[r][mid]>target)
                ub=mid-1;
            else
                lb=mid+1;
        }
        return new int[]{-1,-1};
    }


    int[] bnry_srch_Row_Col_sorted(int[][] a, int target)
    { // sorter for row sorted and column sorted
        int lb=0;
        int ub=a.length-1;
        while(lb<a.length && ub>=0)
        {
            if(target==a[lb][ub])
                return new int[]{lb,ub};
            if(a[lb][ub]<target)
                lb++;
            else
                ub--;
        }
        return new int[]{-1,-1};
    }
    
    int[] sorter(int[][]a, int k)
    {
        int row=a.length, col=a[0].length;
        if(row==1)
            return binary_search(a, col,0,a[0].length,row);
        int rstart=0, rend=row-1,cmid=col/2;
        while(rstart<(rend-1))
        {
            int mid=rstart+(rend-rstart)/2;
            if(a[mid][cmid]==k)
                return new int[]{mid,cmid};
            else if(a[mid][cmid]>k)
                rend=mid;
            else 
                rstart=mid;
        }
        if(a[rstart][cmid]==k)
            return new int[]{rstart,cmid};
        if(a[rstart+1][cmid]==k)
            return new int[]{rstart+1,cmid};
        
        if(k<= a[rstart][cmid-1])
        {
            return binary_search(a, k, 0, cmid-1, rstart);
        }
        if(k<= a[rstart+1][cmid-1])
        {
            return binary_search(a, k, 0, cmid-1, rstart+1);
        }
        if(k>= a[rstart][cmid+1] && k<=a[rstart][col-1])
        {
            return binary_search(a, k, cmid+1, col-1, rstart);
        }
        if(k<= a[rstart+1][cmid+1] && k<=a[rstart+1][col-1])
        {
            return binary_search(a, k, cmid+1,col-1, rstart+1);
        }
        return new int[]{-1,-1};
    }
    public static void main(String args[])
    {
        binary_search_2d ob=new binary_search_2d();
        Scanner sc=new Scanner(System.in);
        int n,tar;
        System.out.println("Enter Size: ");
        n=sc.nextInt();
        int a[][]=new int[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=sc.nextInt();
            }
        }
        // a={{10,20,30,40},{100,}}
        System.out.println("Enter target: ");
        tar=sc.nextInt();
        int ans[]=ob.bnry_srch_Row_Col_sorted(a,tar);
        System.out.println(Arrays.toString(ans));
        sc.close();
    }
}
