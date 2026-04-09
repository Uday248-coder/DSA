//https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-arrays-with-duplicate-elements/1
class Solution {
    ArrayList<Integer> intersection(int[] a, int[] b) {
        ArrayList<Integer> fin = new ArrayList<Integer>();
        int i=0, j=0;
        int n=a.length, m=b.length;
        while(i<n && j<m){
            if(i>0 && a[i]==a[i-1]){
                i++;
                continue;
            }
            if(j>0 && b[j]==b[j-1]){
                j++;
                continue;
            }
            if(a[i]==b[j]){
                fin.add(a[i]);
                i++;
                j++;
            }
            else if(a[i]<b[j])
                i++;
            else
                j++;
        }
        return fin;
    }
}
