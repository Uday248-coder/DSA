//https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/submissions/2009219709/?envType=daily-question&envId=2026-05-21
import java.util.HashSet;

class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        HashSet<Integer> prefixes = new HashSet<>();
        
        for (int val : arr1) {
            while (val > 0) {
                prefixes.add(val);
                val /= 10;
            }
        }
        
        int maxLength = 0;
        
        for (int val : arr2) {
            while (val > 0) {
                if (prefixes.contains(val)) {
                    maxLength = Math.max(maxLength, (int) Math.log10(val) + 1);
                    break;
                }
                val /= 10;
            }
        }
        
        return maxLength;
    }
}
