// https://www.spoj.com/problems/PRATA/

//my brute-force trial.. i got mixed up so bad, will solve it via optimal next


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int p;
        cin >> p;
        int l;
        cin >>l;
        vector<int> cooks(l,0);
        int maxi=INT_MIN;
        for(int i=0;i<l;i++){
            cin >> cooks[i];
            maxi = max(cooks[i],maxi);
        }
        sort(cooks.begin(), cooks.end());
        int count=0;
        int time=0;
        int i=0;
        int outer_loop=2;
        while(count <p){
            int amt=cooks[i];
            int qw=2;
            while(amt<maxi && count <p){
                count ++;
                amt += cooks[i]*(qw++);
            }
            time+=amt;
            if(count >=p){
                cout << time;

                break;
            }
            i++;
            if(i>=l){
                i=0;
                cooks[l-1] += cooks[l-1]*(outer_loop++);
            }
        }
        cout << time <<endl;
    }
    return 0;
}