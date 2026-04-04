//https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
// basic approach find a prefix sum of the array where each index holds the sum of elements upto that index, now on re-traversal we check;
//if the sum at any of these index is 0 (marking elements till that index sum upto 0) or if the same sum appears twice marking the difference between them two to be zero..
// the main issue came with that re--trvaersal being O(n^2) with normal checking loops but now if i use my freq technique as used below its inefficient for real large sums..
// so vani's solution of using a hashmap is the most ideal one i beleive!
// NOTE - WILL HAVE TO IMPLEMENT THAT LATER TOMORWWO!
class Solution {
    // Function to check whether there is a subarray present with 0-sum or not.
    static boolean findsum(int arr[]) {
        int min=arr[0],max=arr[0];
        for(int i=1;i<arr.length;i++){
            arr[i]+=arr[i-1];
            if(arr[i]<min)
                min=arr[i];
            if(arr[i]>max)
                max=arr[i];
                
            if(arr[i-1]==0 || arr[i]==0)
                return true;
        }
        
        min = (min<0)?min*-1 : min;
        int freq[]=new int[Math.abs(max+min+10)];
        for(int i=0;i<arr.length;i++){
                arr[i]+=min;
        }
        for(int i=0;i<freq.length;i++){
            freq[i]=0;
        }
        for(int i=0;i<arr.length;i++){
            freq[arr[i]]++;
            if(freq[arr[i]] > 1)
                return true;
        }
        return false;
        
        
        int my[][]=new int[arr.length][2];
        my[0]={arr[0],0};
        for(int i=1;i<arr.length;i++){
            my[i][0]=my[i-1][0]+arr[i];
            my[i][1]=0;
        }
        for(int i=0;i<my.length;i++){
            if(my[i][0]==0)
                return true;
            my[my[i][0]][1] +=1;
        }
    }
}
