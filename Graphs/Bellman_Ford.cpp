// this is the base implementation made for learning bellman _ ford algorithm
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};
void bellmanford(vector<edge>& E, int n, int e, int src){
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    vector<int> parent(n,-1);
    
    for(int r=1;r<n;r++){
        bool wasupdated = false; // to stop further relaxations if minimum distances are reached.
        for(int i=0;i<e;i++){
            int u=E[i].u;
            int v=E[i].v;
            int w=E[i].w;

            if(dist[u]!= INT_MAX && dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                wasupdated = true;
                parent[v]=u;
            }
        }
        if(!wasupdated)
            break;
    }

    // checking for negative cycles..
    for(int i=0;i<e;i++){
            int u=E[i].u;
            int v=E[i].v;
            int w=E[i].w;
            if(dist[u]!= INT_MAX && dist[u]+w < dist[v]){
                cout << "Negative Cycle Exists" << endl;
                return;
            }
    }
    // to print paths as well
    for(int i=0;i<n;i++){
        if(i== src) continue;
        cout << " Path to " << i << ": ";
        if(dist[i]==INT_MAX){
            cout <<"No path\n";
           continue;
        }
        vector<int> path;
        for(int curr = i ; curr!=-1; curr = parent[curr]){
            path.push_back(curr);
        }

        for(int j=path.size()-1;j>=0;j--){
            cout << path[j];
            if(j!=0)
                cout << " -> ";
        }
        cout << endl;
    }  
    cout << "Shortest Distance From Source: " << src<<endl;
    cout << "Vertex\tDistance" << endl;
    for(int i=0;i<n;i++){
        cout << (char)('A'+i) <<'\t';
        if(dist[i] == INT_MAX)
            cout << "INF {unreachable}";
        else
            cout << dist[i];
        cout <<endl;
    }
}

int main(void){
    int n, e;
    cout << "Enter number of nodes and edges" << endl;
    cin >> n >> e;
    vector<edge> E(e);
    cout << "Enter Edges and thier weights" << endl;
    for(int i=0;i<e;i++){
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    int src;
    cout << "Enter Source: ";
    cin >> src;
    bellmanford(E, n, e, src);
    return 0;
}
