// https://www.geeksforgeeks.org/problems/assembly-line-scheduling/1
/*

You are given:

A 2D array a[][] of size 2*n, where a[i][j] represents the time required to process station j on assembly line i.
A 2D array t[][] of size 2*n where t[0][j] represents the time required to switch from assembly line 1 to assembly line 2, and t[1][j] represents the time required to switch from assembly line 2 to assembly line 1, both between stations j-1 and j.
Entry times e[] of size 2, where e[i] is the time required to enter assembly line i.
Exit times x[] of size 2, where x[i] is the time required to exit assembly line i.



*/

class Solution {
  public:
    int carAssembly(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e,
                    vector<int>& x) {
        int n= a[0].size();
        int f1[n];
        int f2[n];
        f1[0] = e[0] + a[0][0];
        f2[0] = e[1] + a[1][0];
        for(int i=1; i<a[0].size(); i++){
            f1[i] = min(f1[i-1] , f2[i-1]+ t[1][i]) + a[0][i];
            f2[i] = min(f2[i-1] , f1[i-1]+ t[0][i]) + a[1][i];
        }
        f1[n-1] += x[0]; 
        f2[n-1] += x[1];
        return min(f1[n-1], f2[n-1]);
    }
};
