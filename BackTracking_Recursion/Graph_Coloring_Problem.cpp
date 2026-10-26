//https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

// this version gives the first valid colouring that fits right..
class Solution {
  public:
    
    bool isSafe(int** graph,int* color,int c, int v, int N){
        for(int i=0;i<N;i++){
            if(graph[v][i] && color[i]==c){
                return false;
            }
        }
        return true;
    }
    bool solve(int** graph, int* color, int v, int N, int m){
        if(v==N){
            return true;
        }
        for(int c=1;c<=m;c++){
            if(isSafe(graph, color, c, v,N)){
                color[v]=c;
                if(solve(graph, color, v+1, N, m))
                    return true;
                color[v]=0;
            }
        }
        return false;
    }
  
  
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        int** graph = new int*[v];
        for(int i=0;i<v;i++){
            graph[i]=new int[v]();
        }
        for(vector<int> a: edges){
            graph[a[0]][a[1]]=1;
        }
        int color[v];
        return solve(graph, color,0, v, m);
    }
};


// this version gives all valid coloring that fits.
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> graph,vector<int>& color, int c, int v, int N){
    for(int i=0;i<N;i++){
        if(graph[v][i]==1 && color[i]==c){
            return false;
        }
    }
    return true;
}

void solve(vector<vector<int>>& graph, vector<int>& color, int v, int m, int N){
    if(v==N){
        cout << "Solution : "<<endl;
        for(int i=0;i<N;i++){
            cout << (char)('A'+i) << " : " << color[i] << endl;
        }
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        return;
    }
    for(int c=1; c<=m;c++){
        if(isSafe(graph, color, c, v, N)){
            color[v] = c;
            solve(graph, color, v+1, m, N);
            color[v] = 0;
        }
    }
}

int main(){
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    cout << "Enter number of edges: ";
    int e;
    cin >> e;
    cout << "Enter edges one by one: " << endl;
    for(int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    cout << "Enter maximum number of colours that can be used: " ;
    int m;
    cin >> m;
    vector<int> color(n);
    solve(graph,color,0, m,n);
    return 0;
}
