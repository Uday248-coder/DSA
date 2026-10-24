// FULL version of LCS Code in C++
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void lcs(string x, string y){
    int n = x.size() ;
    int m = y.size() ;
    int dp[n+1][m+1];
    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<m;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1]){
               dp[i][j]=dp[i-1][j-1] + 1; 
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int lcs_val = dp[n][m];
    int i=n, j=m;
    string seq="";
    while(i>=0 && j>=0){
        if(x[i-1]==y[j-1]){
            seq = x[i-1] + seq;
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    cout << "Longest Consequetive Sequence: " << seq << " | "<<lcs_val ;
}

int main(void){
    string x;
    string y;
    cout << "Enter Strings: ";
    cin >> x >>y;
    lcs(x,y);
    return 0;
}
