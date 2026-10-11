// base dfs traversal

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
};

bool dfs( vector<vector<int>>& graph, int s, int t,vector<int>& par,vector<bool>& visited){
    if(s == t)
        return true;
    visited[s]=true;
    for(int v=0; v< graph.size();v++){
        if(!visited[v] && graph[s][v]>0){
            par[v]=s;
            if(dfs(graph, v,t,par,visited))
                return true;
        }
    }
    return false;
}

void ford_fulkerson(vector<vector<int>>& cap,int n,int s,int t){
    vector<int> par(n);
    int maxflow=0;
    vector<vector<int>> residual = cap;
    while(true){
        vector<bool> visited(n,false);
        if(!dfs(residual, s, t, par, visited)){
            break;
        }
        int f = INT_MAX;
        for(int v=t; v!=s; v = par[v]){
            int u = par[v];
            f = min(f, residual[u][v]);
        }
        for(int v=t; v!=s;v=par[v]){
            int u=par[v];
            residual[u][v] -= f;
            residual[v][u] += f;
        }
        maxflow +=f;
    }
    cout << "Max-Flow :" << maxflow <<endl;
}

int main(void){
    int n, e;
    cout << "Enter Number of nodes and edges: ";
    cin >> n >> e;
    vector<vector<int>> cap(n, vector<int>(n,0));
    cout << "Enter Edges: " << endl;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin >> u >> v >> w;
        cap[u][v]=w;
    }
    int s, t;
    cout << "Enter Source and sink: ";
    cin >> s >> t;
    cout << endl;
    ford_fulkerson(cap, n, s, t);
    return 0;
}
