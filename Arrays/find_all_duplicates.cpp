//https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
//You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

// using the negative marking technique.. we'll traverse the array and check the pointing indexes.
//TC : O(N)
//SC : O(1){auxilarry space: index pointer} + O(N){result}
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        // negative marking stratergy.
        ArrayList<Integer> answer = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            int ind=Math.abs(nums[i]) -1; // the current element is taken as an index in that array.
            if(nums[ind]<0){ // if the index's element is negative, i.e, the index had been visited before, that means this element was discovered or encounterd before.
                answer.add(ind+1);
            }else{ //  that index is never visited i.e, the current element never appeared before then mark this index as visited by making its element as negative.
                nums[ind]*=-1;
            }
        }
        return answer;
        
    }
}
