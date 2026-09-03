//https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1
// Expected:
// TC : O(N)
// SC : O(1)

//brtue force-wrong for zero handling..
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        long long prod =1;
        for(int i:arr){
            prod*=i;
        }
        vector<int> answer;
        for(int i:arr){
            if(i!=0)
                answer.push_back((int)(prod/i));
            else
                answer.push_back((int)(prod));
        }
        return answer;
    }
};

// brute force - works but O(N^2)
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        // vector<int> prefix_prod(n);
        // vector<int> suffix_prod(n);
        // prefix_prod[0]=1;
        // suffix_prod[n-1]=1;
        // for(int i=1;i<n;i++){
        //     prefix_prod[i]=prefix_prod[i-1] * arr[i];
        //     suffix_prod[n-i-1]=suffix_prod[n-i] * arr[n-i-1];
        // }
        // for(int i=0;i<n;i++){
        //     ans.push_back(prefix_prod[i]*suffix_prod[i]);
        // }
        for(int i=0;i<n;i++){
            ans[i]=1;
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                ans[i]*=arr[j];
            }
        }
        return ans;
    }
};

// works O(N) !! -- prefix and suffix logiccc!
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        vector<int> prefix_prod(n);
        vector<int> suffix_prod(n);
        prefix_prod[0]=1;
        suffix_prod[n-1]=1;
        for(int i=1;i<n;i++){
            prefix_prod[i]=prefix_prod[i-1] * arr[i-1];
            suffix_prod[n-i-1]=suffix_prod[n-i] * arr[n-i];
        }
        for(int i=0;i<n;i++){
            ans[i]=prefix_prod[i]*suffix_prod[i];
        }
        return ans;
    }
};


