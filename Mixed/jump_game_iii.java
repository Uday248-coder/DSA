//https://leetcode.com/problems/jump-game-iii/?envType=daily-question&envId=2026-05-17

// using recursion based path traverssal
class Solution {
    public boolean canReach(int[] arr, int i) {
        if (i < 0 || i >= arr.length || arr[i] < 0) {
            return false;
        }
        
        if (arr[i] == 0) {
            return true;
        }
        
        int jumpLength = arr[i];
        arr[i] = -arr[i]; 
        
        return canReach(arr, i + jumpLength) || canReach(arr, i - jumpLength);
    }
}
