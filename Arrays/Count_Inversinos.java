//https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// EXPECTED TIME COMPLEXITIES : O(N LOGN)
// EXPECTED SPACE COMPLEXITIES : O(N)


// failed with ambiguity. unclear approach lead to unanswered doubts.
class Solution {
    public int inversionCount(int arr[]) {
        int count=0;
        int[] temp=new int[arr.length];
        for(int i=0;i<arr.length;i++){
          temp[i]=arr[i];
        }
        Arrays.sort(temp);
        for(int i=0;i<temp.length;i++){
            int a = Arrays.binarySearch(temp,arr[i]);
            if(i>a)
                count+=Math.abs(a-i);
        }
        return count;
    }
}
