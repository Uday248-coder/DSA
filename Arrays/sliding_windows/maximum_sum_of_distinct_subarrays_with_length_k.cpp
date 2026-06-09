//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

//optimised version
// basically we keep the track of number of elements in the window.
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        long long sum = 0;
        long long maxi = 0;
        bool mov = false;
        for (int i = 0; i < nums.size(); i++) {
            check[nums[i]]++; // here the freq of the current element is incremented, if dicovered for the first time we add it into the map, increasing the size, else if already present the freq value gets incremented.
            sum += nums[i];
            if (i >= k) {
                check[nums[i - k]]--;
                if (check[nums[i - k]] == 0) //  removing all the elements that left thw window and are not present in window as well, helps to maintain the distinct element count of the array
                    check.erase(nums[i - k]);
                sum = sum - nums[i - k];
            }
            if (i >= k - 1 && check.size() == k) // now if all the k elements are distinct, then the map must have k enteries or k keys making it of size k -- thats the gold!!
                maxi = max(maxi, sum);
        }
        return maxi;
    }
};
