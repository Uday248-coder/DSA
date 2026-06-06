//https://leetcode.com/problems/two-sum/?envType=problem-list-v2&envId=array
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> x(nums);
        sort(x.begin(), x.end());
        int i=0;
        int j=n-1;
        vector<int> ans ={};
        while(i<j){
            if(x[i]+x[j] == target){
                for(int a=0;a<n;a++)
                    if(x[i] == nums[a]){
                        ans.push_back(a);
                        break;
                    }
                for(int a=0;a<n;a++){
                    if(x[j]==nums[a] && a!=ans[0]){
                        ans.push_back(a);
                        break;
                    }
                }
                break;
            }
            else if(x[i]+x[j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
