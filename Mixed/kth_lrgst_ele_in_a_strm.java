//https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1
class Solution {
    static ArrayList<Integer> kthLargest(int[] arr, int k) {
        // code here
        int n=arr.length;
        ArrayList<Integer> ans= new ArrayList<Integer>(); 
        int val=arr[0];
        for(int i=0;i<k;i++){
            if(i!=k-1)
                ans.add(-1);
            val = (arr[i]<val)? arr[i] : val;
            // System.out.println("Val: "+val + "|  arr[i]: "+arr[i] );
        }
        // System.out.println("JBSJHVJAVJ");
        for(int i=k-1;i<n;i++){
            Arrays.sort(arr,0,i+1);
            // System.out.println("Val: " +  arr[i-(k-1)]);
            ans.add(arr[i-(k-1)]);
        }
        return ans;
    }
}
