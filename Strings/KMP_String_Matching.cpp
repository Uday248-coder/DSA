#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
    string text, pattern;
    cout << "Enter Text String and Pattern String: ";
    cin >> text >> pattern;
    int lps[pattern.size()] = {0};
    for(int i=1, len =0;i<pattern.size();){
        if(pattern[i] == pattern[len]){
            lps[i++] = ++len;
        }
        else if(len>0){
            len=lps[len-1];
        }
        else{
            lps[i++]=0;
        }
    }
    int matched=0;
    for(int i=0, j=0; i<text.size();){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j==pattern.size()){
            matched++;
            cout << i-j << " ";
            j = lps[j-1];
        }
        else if(i < text.size() && text[i] != pattern[j]){
            if(j>0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }   
    if(matched == 0)
        cout << "Found No Match!" << endl;
    return 0;
}
