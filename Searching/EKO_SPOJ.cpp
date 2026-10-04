//https://www.spoj.com/problems/EKO/

// TC : O(N* LOG(N))
// SC: O(N)

// Algorithm was picture perfect: got bound errors- made low=0, then made integer variables as long long for handling larger sums, made the tree vector call in possible fucntion as call by refrence rather than call by value so that for each call the orginal vector is passed rather than any copy is created-eating more memory than needed.

#include <iostream>
#include <vector>
using namespace std;
// trying binary search approch

bool possible(vector<int>& t, long long val, long long req){
    long long sum=0;
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
    long long n,m;
    cin >> n >> m;
    vector<int> trees;
    long long high=-1,low=0;
    long long x;
    for(int i=0;i<n;i++){
        cin >> x;
        trees.push_back(x);
        high = max(high,x);
        low = min(low,x);
    }
    long long ans=0;
    while(low <= high){
        long long mid = low + (high-low)/2;
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
