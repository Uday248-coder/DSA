//lc121
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// better solution

// since needed to find the difference between the buy and sell we just took care of the minimum val discovered so far while traversing 
// and then finding the difference between that min and the current element and storing the maximum difference of this kind found so far
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], n = prices.size();
        int max=0; // will store our required difference
        for(int i=0;i<n;i++){
            if(min>prices[i]) // updates for a new min if found
                min=prices[i];
            if(max < prices[i]-min){ // checks the difference of the curr element and the latest discovered minimum value.
                max = prices[i]-min;
                cout << "stock: " << prices[i] << '\n' << "MIN:" << min << endl;
                cout << max << " NEW MAX" << endl;
            }
                
        }
        return max;
    }
};

// ---------------------------

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // this is not sliding window attempt. this is still trying every combiantion fundamentally. so this is wrong!!!!!!
        int max = 0, n = prices.size();
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; i + j < n; j++) {
                if (prices[i + j] - prices[j] > max) {
                    max = prices[i + j] - prices[j];
                    cout << max;
                }
            }
        }
        return max;
    }
};
