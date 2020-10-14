#include <stdio.h>

int M,N;
int box[1001][1001] = {0};
int visited[1001][1001] = {0};

int main(){
    scanf("%d %d",&M,&N);

    int status;

    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            scanf("%d",&status);

            box[y][x] = status;
        }
    }
}