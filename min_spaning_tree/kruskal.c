#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct {
    int u,v,w;
}Edge;

int find(int parent[],int i){
    if(parent[i]==i)
        return i;
    return find(parent, parent[i]);
}

void unite(int parent[], int rank[], int x, int y){
    x=find(parent,x);
    y=find(parent,y);

    if(x!=y){
        if(rank[x]<rank[y])
            parent[x]=y;
        else if(rank[x]>rank[y])
            parent[y]=x;
        else{
            parent[y]=x;
            rank[x]++;
        }
    }
}
int cmp(const void* a, const void* b){
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main(void){
    int v,e;
    scanf("%d %d",&v,&e);
    Edge edges[e]; 
    for(int i=0;i<e;i++)
        scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
    qsort(edges,e,sizeof(Edge),cmp);
    int parent[v],rank[v];
    for(int i=0;i<v;i++){
        parent[i]=i;
        rank[i]=0;
    }
    int total=0;

    for(int i=0;i<e;i++){
        int x=edges[i].u;
        int y=edges[i].v;
        if(parent[x]!=parent[y]){
            unite(parent,rank,x,y);
            pritnf("%d - %d:%d\n",x,y,edges[i].w);
            total+=edges->w;
        }
    }
    printf("Total Weight: %d",total);
    return 0;
    
}
