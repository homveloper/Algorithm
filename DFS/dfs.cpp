#include <stdio.h>
#include <memory.h>

int V, E;
int graph[8][8] = {0};
int visited[8] = {0};

void dfs(int v){
    printf("%d",v);

    visited[v] = 1;

    for(int i=1; i<=V; i++){
        if(graph[v][i] && !visited[i]){
            dfs(i);
        }
    }
}

void main(){
    scanf("%d %d",&V,&E);

    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));

    int y,x;
    for(int i=0; i<E; i++){
        scanf("%d %d",&y,&x);
        graph[y][x] = graph[x][y] = 1;
    }

    for(int i=1;i<=V; i++){
        memset(visited, 0, sizeof(visited));
        dfs(i);
        printf("\n");
    }
}