//https://www.spoj.com/problems/ANARC05B/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,m;
    while(true){
        cin >> n;
        if(n<=0)
            return 0;
        vector<int> s1;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            s1.push_back(x);
        }
        
        cin >> m;
        if(m<=0)
            return 0;
        vector<int> s2;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            s2.push_back(x);
        }
        int ans=0;
        int sum1=0, sum2 =0;
        int i=0,j=0;
        while(i<=n && j<=m){
            if(s1[i]>s2[j]){
                sum2+=s2[j];
                j++;
            }else if(s1[i] < s2[j]){
                sum1 +=s1[i];
                i++;
            }
            else{
                ans = ans + s1[i] +max(sum1,sum2);
                sum1=0;
                sum2=0;
                i++;
                j++;
            }
        }
        while(i<n){
            sum1+=s1[i++];
        }
        while(j<m){
            sum2+=s2[j++];
        }
        ans += max(sum1,sum2);
        cout << ans << endl;
    }
    return 0;
}
