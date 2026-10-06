//https://www.spoj.com/problems/AGGRCOW/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool can_place(vector<int>& stalls, int c, int min_dis){
    int last =0;
    c--; // placing the first cow at stall at index 0.
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-stalls[last] >=min_dis){
            c--;
            last = i;
        }
    }
    if(c<=0)
        return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> stalls;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            stalls.push_back(x);
        }
        sort(stalls.begin(), stalls.end());
        int high = stalls[n-1] - stalls[0];
        int low = 1;
        int ans;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(can_place(stalls, c, mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
