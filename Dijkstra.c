#include <stdio.h>
#include <stdlib.h>

#define INF 999999
#define MAX 100

int minDistance(int visited[], int dist[], int n){
    int min=INF,min_ind=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && dist[i]<min){
            min=dist[i];
            min_ind=i;
        }
    } 
    return min_ind;
}

void dijsktra(int graph[MAX][MAX],int src,int n){
    int visited[MAX]={0};
    int dist[MAX];
    for(int i=0;i<n;i++)
        dist[i]=INF;
    dist[src]=0;

    for(int c=0;c<n-1;c++){
        int u=minDistance(visited,dist,n);
        visited[u]=1;
        for(int v=0;v<n;v++){
            if(graph[u][v] && !visited[v] && dist[u]+graph[u][v] < dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
        printf("Shortest Distances from Source: %d",src);
        for(int i=0;i<n;i++){
            printf("To %d :--> %d\n",i,dist[i]);
        }
    }
}
int main() {
    int n, e;
    scanf("%d%d", &n, &e);
    int graph[MAX][MAX] = {0};
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        graph[u][v] = graph[v][u] = w;
    }
    dijkstra(graph, n, 0);
    return 0;
}
