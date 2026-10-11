#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    string text, pattern;
    cout << "Enter text and pattern: ";
    cin >>  text >> pattern ; 

    long long p_hash =0;
    long long t_hash =0;
    int mod = 1e9 + 7;
    int base = 256;
    long long highestplace = 1;
    for(int i=0;i<pattern.size()-1;i++){
        highestplace = highestplace*base %mod;
    }
    for(int i=0;i<pattern.size();i++){
        p_hash = (base*p_hash +pattern[i])%mod;
        t_hash = (base*t_hash +text[i])%mod;
    }
    int matched=0;
    for(int i=0;i<=text.size()-pattern.size();i++){
        if(t_hash == p_hash){
            int j=0;
            while(j<pattern.size() && text[i+j] == pattern[j])
                j++;
            if(j==pattern.size()){
                cout << i << " ";
                matched++;
            }
        }
        char outgoing = text[i];
        char incoming = text[i + pattern.size()];
        t_hash = ((t_hash - outgoing*highestplace)*base + incoming) % mod;
        if(t_hash < 0)
            t_hash +=mod;
    }
    if(matched==0){
        cout << "No match Found." << endl;
    }
    return 0;
}
