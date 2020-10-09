#include <iostream>
#include <memory.h>
using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int T,X,Y,K;

int graph[50][50] = {0};
int visited[50][50] = {0};

void dfs(int y,int x){

    visited[y][x]++;

    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];

        if(ny<0 || ny>=Y || nx<0 || nx>=X)
            continue;
        
        if(graph[ny][nx] && !visited[ny][nx]){
            dfs(ny,nx);
        }
    }
}

int main()
{
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &X, &Y, &K);

        memset(graph,0,sizeof(graph));
        memset(visited,0,sizeof(visited));

        int result = 0;

        int x,y;
        for(int j=0; j<K; j++){
            scanf("%d %d",&x,&y);
            graph[y][x] = 1;
        }

        for(int j=0; j<Y; j++){
            for(int k=0; k<X; k++){
                if(graph[j][k] && !visited[j][k]){
                    result ++;
                    dfs(j,k);
                }
            }
        }

        cout<<result<<endl;
    }
}