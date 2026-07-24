// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// Time Complexity : O(N)
// Space Complexity: O(1)

class Solution {
    public int minJumps(int[] arr) {
        if (arr.length <= 1)
            return 0;
        int jumps = 0;
        int currentReach = 0;       // End of the range reachable using the current number of jumps.
        int farthestReach = 0;      // Farthest index we can reach while scanning the current range.
        for (int i = 0; i < arr.length - 1; i++) {
            farthestReach = Math.max(farthestReach, i + arr[i]);   // Expand the farthest reachable index.
            if (i == currentReach) {                               // Finished scanning the current reachable range.
                if (farthestReach == currentReach)                 // Couldn't extend the range → stuck.
                    return -1;
                currentReach = farthestReach;                      // Begin exploring the next reachable range.
                jumps++;                                           // One jump is now committed.
            }
        }
        return jumps;
    }
}
