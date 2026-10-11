// small implementation of floyd washell algorithm

void Floyd_Washall(vector<edge>& E, int n, int e){
    int INF = 1e9;
    int adj[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = (i==j)?0 : INF;
        }
    }
    for(int i=0;i<e;i++){
        int u=E[i].u;
        int v=E[i].v;
        int w=E[i].w;
        if(w < adj[u][v])
            adj[u][v]=w;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    cout << "All pair shortest path matrix: " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]!=INF)
                cout << adj[i][j] << " ";
            else
                cout << "INF " ;
        }
        cout << endl;
    }
}

