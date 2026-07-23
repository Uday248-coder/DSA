//https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// EXPECTED TIME COMPLEXITIES : O(N LOGN)
// EXPECTED SPACE COMPLEXITIES : O(N)

// burte-force -> just linear checks -> TIME: O(N^2)
class Solution {
    public int inversionCount(int arr[]) {
        int count=0;
        for(int i=0;i<arr.length-1;i++){
            for(int j=i+1;j<arr.length;j++){
                if(arr[i]>arr[j])
                    count++;
            }
        }
        return count;
    }
}
