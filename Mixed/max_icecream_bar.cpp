//https://leetcode.com/problems/maximum-ice-cream-bars/?envType=daily-question&envId=2026-06-21

//brute force approach..
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins){
                count++;
                coins-=costs[i];
            }
            if(coins<=0)    
                break;
        }
        return count;
    }
};
