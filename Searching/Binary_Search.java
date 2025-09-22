package Searching;
// shall be showcasing different Question patterns on binary search 
// import java.util.*;
class Binary_search
{
    // floor of a number -- returns the largest num in array which is smaller than the target itself
    int floor(int[] arr,int target)
    {

        int lb=0,ub=arr.length;
        while(lb<=ub)
        {
            int mid=lb + (ub-lb)/2;
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]>target)
                ub=mid-1;
            else
                lb=mid+1;
        }
        if(lb>ub) 
            return lb;
        else   
            return -1;
    }

    // ceil of a number -- returns the smallest num in array which is larger than the target itself
    int ceil(int[] arr,int target)
    { 
        int lb=0,ub=arr.length;
        while(lb<=ub)
        {
            int mid=lb + (ub-lb)/2;
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]>target)
                ub=mid-1;
            else
                lb=mid+1;
        }
        if(lb>ub) 
            return -1;
        else   
            return ub;
    }
    // ceil variation -- Return the smallest character in array that is lexicographically greater than target. 
    //                   If such a character does not exist, return the first character in letters.
    char nextGreatestLetter(char[] letters, char tar) {
        int l=0,u=letters.length-1;
        while(l<=u)
        {
            int m=l+(u-l)/2;
            if(letters[m]>tar)
                u=m-1;
            else
                l=m+1;
        } 
        return letters[l%letters.length];   
    }


    // Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
    public int[] searchRange(int[] nums, int target) {
        /*
        // approach 1 == tried doing everything in one loop
        int t[]={Integer.MAX_VALUE,Integer.MIN_VALUE};
        int lb=0,ub=nums.length;
        while(lb<=ub)
        {
            int mid=lb + (ub-lb)/2;
            if(nums[mid]==target)
            {

                t[0]=(t[0]<mid)?t[0]:mid;
                t[1]=(t[1]>mid)?t[1]:mid;
            }
            else if(nums[mid]>target)
                ub=mid-1;
            else
                lb=mid+1;
        }
        if(t[0]==Integer.MAX_VALUE || t[1]==Integer.MIN_VALUE)
            return {-1,-1};
        return t;
        */
        int[] t= {(search(nums,target,true)),(search(nums,target,false))};
        return t;
        
    }

    int search(int[] arr, int key, boolean frst)
    {
        int t=-1;
        int lb=0,ub=arr.length-1;
        while(lb<=ub)
        {
            int mid=lb + (ub-lb)/2;
            if(arr[mid]==key)
            {
                t=mid;
                if(frst)
                    ub=mid-1;
                else
                    lb=mid+1;
                    
            }
            else if(arr[mid]>key)
                ub=mid-1;
            else
                lb=mid+1;
        }
        return t;
    }

    // Fidning peak index in an BIOTONIC ARRAY -- Q852 leetcode.
    public int peakIndexInMountainArray(int[] a) {
        int lb=0,ub=a.length-1;
        while(lb<=ub)
        {
            int m=lb+(ub-lb)/2;
            if(a[m]>=a[m+1] && a[m]>=a[m-1])
                return m;
            else if(a[m]>=a[m+1] && a[m]<=a[m-1])
                ub=m-1;
            else
                lb=m+1;
        }
        return -1;
    }

    public int RotatedSortedArrayBinarySrch(int[] nums, int target) {
        int pvt=pivot(nums);
        if(pvt==-1)
            return bnry_srch(nums,target,0,nums.length-1);
        if(nums[pvt]==target)
            return pvt;
        if(nums[0]<=target)
            return bnry_srch(nums,target,0,pvt-1);
        return bnry_srch(nums,target,pvt+1,nums.length-1);
    }

    int bnry_srch(int[] a, int t, int l, int u)
    {
        while(l<=u)
        {
            int mid=l + (u-l)/2;
            if(a[mid]>t)
                u=mid-1;
            else if(a[mid]<t)
                l=mid+1;
            else
                return mid;
        }
        return -1;
    }
    // this wouldnt work well for cases with duplicate/ repeating numbers in array, refer to line 169's modification
    int pivot(int[] a){
        int l=0,u=a.length-1;
        while(l<=u)
        {
            int mid=l+(u-l)/2;
            if(mid<u && a[mid]>a[mid+1])
                return mid;
            if(mid>l && a[mid]<a[mid-1])
                return mid-1;
            /* // replace this code block with the one below (the if else in line 180) for checking in a repeated sorted array 
                if(a[mid]==a[l] && a[mid]==a[u])
                {
                    if(a[l]>a[l+1])
                    return l;
                    l++;
                    if(a[u]<a[u-1])
                        return u-1;
                    u--;
                }
                if(a[l]<a[mid] || (a[l]==a[mid] && a[mid]>a[u]))
                    l=mid+1;
                else
                    u=mid-1;
             */
            if(a[mid]<a[l])
                u=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }


}