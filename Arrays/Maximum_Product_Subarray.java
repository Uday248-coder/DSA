//https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
// TIME :: O(N)
// SPACE :: O(1)

// it is kadane's algo with optimisation to fit problem's niche as we have to take care of the negative numbers as well na, here we have product not sum, so two negative can create a greater positive product than two positive multiplication.

class Solution {
    int maxProduct(int[] arr) {
        int maxi=arr[0];
        int mini=arr[0];
        int prod=arr[0];
        for(int i=1;i<arr.length;i++){
            int curmax = maxi*arr[i];
            int curmin = mini*arr[i];
            maxi = Math.max(arr[i], Math.max(curmax, curmin));
            mini = Math.min(arr[i], Math.min(curmax, curmin));
            prod = Math.max(prod, maxi);
        }
        return prod;
    }
}
