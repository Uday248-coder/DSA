// https://leetcode.com/problems/construct-uniform-parity-array-i/description/?envType=daily-question&envId=2026-09-02

// i was hassling around so much thinking so much but what is the question really about is so idotically simply..
// can i construct an array using the elements of the array in nums1 of same size as of nums1, where parity(oddness or eveness) is same, i.e, all elements are either odd or even.
// now if nums1 has all elements as either odd or even, then straightaway we can return true as it already fulfils that condition.
// if it has mixed odd or even elements, still we can make it all even or odd as odd - even = odd.. so we can make all numbers to be odd by subtracting each even number by some odd number.. converting the parity.




// TC: O(1)
// SC: O(1)
class Solution {
    public boolean uniformArray(int[] nums1) {
        return true;
    }
}
