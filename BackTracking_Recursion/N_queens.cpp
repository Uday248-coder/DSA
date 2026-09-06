//https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> answer;
    bool isSafe(int** board,int n,int r,int c){
        for(int i=0;i<r;i++){
            if(board[i][c])
                return false;
        }
        for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--){
            if(board[i][j])
                return false;
        }
        for(int i=r-1, j=c+1; i>=0 && j<n; i--, j++){
            if(board[i][j])
                return false;
        }
        return true;
    }
    void solve(int** board,int r,int n){
        if(r==n){
            vector<string> sol;
            for(int i=0;i<n;i++){
                string row="";
                for(int j=0;j<n;j++){
                    row+= (board[i][j]?'Q':'.');
                }
                sol.push_back(row);
            }
            answer.push_back(sol);
            return;
        }
        for(int c=0;c<n;c++){
            if(isSafe(board, n, r, c)){
                board[r][c]=1;
                solve(board,r+1, n);
                board[r][c]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // const int N=n;
        // int board[N][N] ={0};
        int** board = new int*[n];
        for (int i = 0; i < n; ++i) {
            board[i] = new int[n](); 
        }
        solve(board,0,n);
        return answer;
    }
};
