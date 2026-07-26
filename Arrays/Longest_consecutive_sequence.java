//https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
// TIME : O(N)
// SPACE : O(N)

class Solution {
    public int longestConsecutive(int[] arr) {
        // using a hash set it will automatically store things in a prominenet way.. and we can use the .contains function to search and get back the result.
        HashSet<Integer> x = new HashSet<>();
        for(int i:arr)
            x.add(i);
        int maxi=0;
        for(int i:x){
            if(i==0 || !x.contains(i-1)){
                int curr=i;
                int len=1;
                while(x.contains(curr+1)){
                    curr++;
                    len++;
                }
                maxi = Math.max(maxi,len);
            }
        }
        return maxi;
    }
}
