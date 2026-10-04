//https://www.spoj.com/problems/EKO/

// TC : O(N* LOG(N))
// SC: O(N)

// wrong approah, full with errors
#include <iostream>
#include <vector>
using namespace std;
// trying binary search approch

bool possible(vector<int> t, int val, int req){
    int sum=0;
    for(int i:t){
        if(i>=val){
            sum += i-val;
        }
    }
    if(sum >=req)
        return true;
    return false;
}

int main(void){
    int n,m;
    cin >> n >> m;
    vector<int> trees;
    int high=-1,low=99999;
    int x;
    for(int i=0;i<n;i++){
        cin >> x;
        trees.push_back(x);
        high = max(high,x);
        low = min(low,x);
    }
    int ans=0;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(possible(trees, mid, m)){
            ans = mid;
            low = mid+1; // since we are finding the best possible answer.
        }
        else{
            high = mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}
