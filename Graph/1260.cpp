#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

queue<int> q;
int N, M, V;

int graph[1001][1001] = {0};
int visited[1001] = {0};

void dfs(int v)
{
    printf("%d ",v);
    visited[v] = 1;

    for (int i = 1; i <= N; i++)
    {
        if (graph[v][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

void bfs(int v){
    visited[v] = 1;
    q.push(v);

    while(!q.empty()){
        v = q.front();
        q.pop();

        printf("%d ",v);

        for(int i=1; i<=N; i++){
             if(graph[v][i] && !visited[i]){
                 q.push(i);
                 visited[i] = 1;
             }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &V);

    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < M; i++)
    {
        int y, x;

        scanf("%d %d", &y, &x);
        graph[y][x] = 1;
        graph[x][y] = 1;
    }
    dfs(V);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    bfs(V);
}