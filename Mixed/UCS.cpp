// trying daa question UCS.. [][][][][] RAW CODE NEEDS FIXING A LOT.. PLEASE REDO THE CODE OR ASK AI FOR FIXES.
include <bits/stdc++.h>
using namespace std;

void BackTrack(int[][] dp,string x, string y, int i, int j, string seq, vector<string> &list){
    if (i==0 || j==0){
        reverse(seq.begin(), seq.end());
        list.push_back(seq);
        return;
    }
    else if(x[i]==y[j]){
        BackTrack(dp,x,y,i-1, j-1, seq + x[i], list); //diagonal
        BackTrack(dp,x,y,i-1, j, seq , list); // left
        BackTrack(dp,x,y,i, j-1, seq , list); // right
    }
    else if(dp[i-1][j]>dp[i][j-1]){
        BackTrack(dp,x,y,i-1, j, seq , list); // left
    }
    else if(dp[i][j-1]>dp[i-1][j]){
        BackTrack(dp,x,y,i, j-1, seq , list); // left
    }
    else{
        BackTrack(dp,x,y,i-1, j, seq , list); // left
        BackTrack(dp,x,y,i, j-1, seq , list); // left
    }
}
bool isDistinct(string z){
    unordered_map<char, int> map;
    for(char c:z){
        map[c]++;
        if(map[c]>1)
            return false;
    }
    return true;
}
vector<string> UCS(string x, string y){
    int n=x.size(), m=y.size();
    int dp[n][m];
    for(int i=0;i<n;i++)
        dp[i][0]=0;
    for(int i=0;i<m;i++)
        dp[0][i]=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(x[i]==y[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    vector<string> list; 
    vector<string> answer; 
    BackTrack(dp,x,y,n,m,"", list);
    for(string x: list){
        if(x.size() > floor((n+m)/3)  && isDistinct(x)){
            answer.push_back(x);
        }
    }
    return answer; 
}
