#include <stdio.h>
#include <memory.h>

int M, N, x = -1,y = -1;
int day = 0;
int box[1000][1000] = {0};
int visited[1000][1000] = {0};

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void dfs(int y,int x){
    visited[y][x] = 1;
    box[y][x] = 1;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        
        if(box[ny][nx] == 0 && !visited[ny][nx]){
            dfs(ny,nx);
        }
    }
    day++;
}

void main(){
    
    scanf("%d %d",&M,&N);

    memset(box,0,sizeof(box));
    memset(visited,0,sizeof(visited));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d",box[i][j]);

            if(tomato == 1 && y == -1 && x == -1){
                y = i;
                x = j;
            }
        }
    }

    dfs(y,x);

    printf("%d",day);
}