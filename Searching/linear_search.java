package Searching;
// import java.util.*;
class Linear_search
{

    int search1(int[] a,int target)
    {
        for(int i=0;i<a.length;i++)
        {
            if(target == a[i])
            {
                return i;
            }
        }
        return Integer.MIN_VALUE;
    }
    boolean search2(int[] a,int target)
    {
        for(int i:a)
        {
            if(target == i)
            {
                return true;
            }
        }
        return false;
    }
    public static void main(String args[])
    {
        Linear_search obj=new Linear_search();
        int[] a = {20,300,10000,2,-78,16,-69,-42000,12,-9001};

        int target1 = -78;
        int target2 = 9999;
        // int target3 = 20;

        System.out.println("The position of target 1 is: "+(obj.search1(a ,target1)+1));
        System.out.println("Is target 2 present in the array: "+(obj.search2(a ,target2)));
        
        
    }
}