// https://www.spoj.com/problems/PRATA/

// Binary Search over possible answers
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> r, int p, int limit){
    int total=0;
    for(int i: r){
        int curr_time=0;
        int count=0;
        int multiplier =1;

        while( curr_time + i*multiplier <=limit){
            curr_time += i*multiplier;
            multiplier ++;
            count++;
        }
        total +=count;
        if(total >=p)
            return true;
    }
    return false;
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int p,l;
        cin >> p;
        cin >>l;
        vector<int> rank(l,0);
        int mini = 10;
        for(int i=0;i<l;i++){
            cin >> rank[i];
            mini = min(rank[i], mini);
        }
        int low=0;
        int high = mini * p* (p+1) / 2;
        int ans=high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(rank, p, mid)){
                ans = mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
