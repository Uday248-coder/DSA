//https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

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
