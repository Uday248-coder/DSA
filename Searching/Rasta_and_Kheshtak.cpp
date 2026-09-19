// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/rasta-and-kheshtak/

// Binary search + Rolling 2D hash + Comparing Hashes

// REDO YOUR VERSION!

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const ull P1 = 173;
const ull P2 = 137;

int n, m, x, y;
vector<vector<int>> A, B;

vector<vector<ull>> prefA, prefB;
vector<ull> pw1, pw2;

ull getHash(vector<vector<ull>>& pref, int r, int c, int k) {
    int r2 = r + k;
    int c2 = c + k;

    ull res = pref[r2][c2]
            - pref[r][c2]
            - pref[r2][c]
            + pref[r][c];

    return res * pw1[700 - r] * pw2[700 - c];
}

void buildPrefix(vector<vector<int>>& mat, vector<vector<ull>>& pref) {
    int N = mat.size();
    int M = mat[0].size();

    pref.assign(N + 1, vector<ull>(M + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pref[i + 1][j + 1] =
                pref[i][j + 1] +
                pref[i + 1][j] -
                pref[i][j] +
                (ull)mat[i][j] * pw1[i] * pw2[j];
        }
    }
}

bool check(int k) {
    if (k == 0) return true;

    if (k > min({n, m, x, y}))
        return false;

    unordered_set<ull> s;
    s.reserve((n - k + 1) * (m - k + 1) * 2);

    for (int i = 0; i + k <= n; i++) {
        for (int j = 0; j + k <= m; j++) {
            s.insert(getHash(prefA, i, j, k));
        }
    }

    for (int i = 0; i + k <= x; i++) {
        for (int j = 0; j + k <= y; j++) {
            if (s.count(getHash(prefB, i, j, k)))
                return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    A.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    cin >> x >> y;

    B.assign(x, vector<int>(y));

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> B[i][j];

    pw1.resize(701);
    pw2.resize(701);

    pw1[0] = pw2[0] = 1;

    for (int i = 1; i <= 700; i++) {
        pw1[i] = pw1[i - 1] * P1;
        pw2[i] = pw2[i - 1] * P2;
    }

    buildPrefix(A, prefA);
    buildPrefix(B, prefB);

    int lo = 0;
    int hi = min({n, m, x, y});

    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;

        if (check(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    cout << lo << '\n';

    return 0;
}


// my uncomplete vversoion

#include <iostream>
using namespace std;
bool feasible(int k, vector<vector<int>>A, vector<vector<int>>B){
    int base=1009;
    int p=k-1;
    vector<vector<long>> Row_Hashed_A;
    vector<long> row_B;
    for(int row=0;row<A.size();row++){
        vector<long> row_A;
        long sum=0;
        for(int i=0;i<k;i++){
            sum +=A[row][i]*pow(1009,p);
            p--;
        }
        row_A.push_back(sum);
        long prevsum = sum;
        for(int i=k;i<A.size();i++){
            sum = (prevsum - (A[row][i-k]*pow(1009,k-1)) )*1009 + A[row][i];
            row_A.push_back(sum);
            prevsum=sum;
        }
        Row_Hashed_A.push_back(row_A);
    }
    vector<vector<long>> hashed_A;
    p=k-1;
    for(int col=0;col<Row_Hashed_A.size();col++){
        vector<long> col_A;
        long sum=0;
        for(int i=0;i<k;i++){
            sum +=Row_Hashed_A[i][col]*pow(1009,p);
            p--;
        }
        col_A.push_back(sum);
        long prevsum=sum;
        for(int i=k;i<Row_Hashed_A.size();i++){
            sum = (prevsum - (Row_Hashed_A[i-k][col]*pow(1009,k-1)) )*1009 + Row_Hashed_A[i][col];
            col_A.push_back(sum);
            prevsum=sum;
        }
        hashed_A.push_back(col_A);
    }
    // hashing B now.
    p=k-1;
    vector<vector<long>> Row_Hashed_B;
    for(int row=0;row<B.size();row++){
        vector<long> row_B;
        long sum=0;
        for(int i=0;i<k;i++){
            sum +=B[row][i]*pow(1009,p);
            p--;
        }
        row_B.push_back(sum);
        long prevsum = sum;
        for(int i=k;i<B.size();i++){
            sum = (prevsum - (B[row][i-k]*pow(1009,k-1)) )*1009 + B[row][i];
            row_B.push_back(sum);
            prevsum=sum;
        }
        Row_Hashed_B.push_back(row_B);
    }
    vector<vector<long>> hashed_B;
    p=k-1;
    for(int col=0;col<Row_Hashed_B.size();col++){
        vector<long> col_B;
        long sum=0;
        for(int i=0;i<k;i++){
            sum +=Row_Hashed_B[i][col]*pow(1009,p);
            p--;
        }
        col_B.push_back(sum);
        long prevsum=sum;
        for(int i=k;i<Row_Hashed_B.size();i++){
            sum = (prevsum - (Row_Hashed_B[i-k][col]*pow(1009,k-1)) )*1009 + Row_Hashed_B[i][col];
            col_B.push_back(sum);
            prevsum=sum;
        }
        hashed_B.push_back(col_B);
    }
    // now i am checking all squares to see if any matches!
}

int main() {
    int n, m;
    cin>> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
        }
    }
    int x,y;
    cin >> x >> y;
    vector<vector<int>> B(x, vector<int>(y));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin >> B[i][j];
        }
    }
    int l=0, h= min(min(x,y), min(n,m));
    int ans=-1;
    while(l<=h){
        int m = l + (h-l)/2;
        if(feasible(k, A, B)){
            ans = m;
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
}

