#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool bfs( vector<vector<int>>& graph, int s, int t,vector<int>& par ){
    vector<bool> visited(graph.size(),false);
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<graph.size();v++){
            if(!visited[v] && graph[u][v]>0){
                par[v]=u;
                visited[v]=true;
                q.push(v);
            }
        }
    }
    return visited[t];
}

void Edmund_karp(vector<vector<int>>& cap,int n,int s,int t){
    vector<int> par(n);
    int maxflow=0;
    vector<vector<int>> residual = cap;
    while(bfs(residual, s, t, par)){
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
    Edmund_karp(cap, n, s, t);
    return 0;
}
