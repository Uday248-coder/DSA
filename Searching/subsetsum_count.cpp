//https://www.spoj.com/problems/SUBSUMS/

// current bruteforce.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long count=0;
    int n;
    int a,b;
    cin >> n >> a >> b;
    if(a<=0 && b>0)
        count++;
    vector<int> num(n);
    vector<int> pref(n);
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    pref[0]=num[0];
    for(int i=0;i<n;i++){
        pref[i]+=pref[i-1] + num[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(pref[j] >=a && pref[j]<=b)
                count++;
        }
    }
    cout << count;
}
