//https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1
class Solution {
    public boolean isMaxHeap(int[] arr) {
        // if(arr.length == 2)
        //     return (arr[0]>arr[1])?true:false;
        // if(arr.length < 1)
        // return false;
        // for(int i=0;i<arr.length;i++){
        //     if(2*i+2 >= arr.length)
        //         break;
        //     if(arr[i]<arr[2*i+1] || arr[i]<arr[2*i+2])
        //         return false;
        // }
        // return true;
        
        int n=arr.length;
        for(int i=0;i<= (n/2)-1 ;i++){
            int l = 2*i +1;
            int r = 2*i +2;
            if(l<n && arr[l]>arr[i])
                return false;
            if(r<n && arr[r]>arr[i])
                return false;
        }
        return true;
    }
}
