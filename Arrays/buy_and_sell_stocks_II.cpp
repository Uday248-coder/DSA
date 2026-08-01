//
// TIME : O(N)
// SPACE : O(N)

// Trash Approach. fails. bad failure.
class Solution {
  public:
    vector<int> transaction(vector<int> arr,int start, int end){
        vector<int> indexes(2,start);
        int mini=start;
        int maxi_profit=0;
        for(int i=start;i<=end;i++){
            if(arr[i]<arr[mini]){
                mini=i;
            }
            if(maxi_profit < arr[i] - arr[mini]){
                maxi_profit = arr[i] - arr[mini];
                indexes[0] = mini;
                indexes[1] = i;
            }
        }
        return indexes;
    }
  
    int maxProfit(vector<int> &prices) {
        vector<int> first = transaction(prices, 0, prices.size()-1);
        int ans = prices[first[1]] - prices[first[0]];
        first = transaction(prices,0,first[0]-1);
        int temp = prices[first[1]] - prices[first[0]];
        
        first = transaction(prices,first[1]+1, prices.size()-1);
        int temp2 = prices[first[1]] - prices[first[0]];
        
        ans += max(temp, temp2);
        return ans;
    }
};
