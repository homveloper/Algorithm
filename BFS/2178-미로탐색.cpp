#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

const int EMPTY = 1;
const int WALL = 0;

const tuple<int,int> D[] = {{-1,0},{1,0},{0,-1},{0,1}};
int N, M;
int B[100][100];
int V[100][100];

void Input()
{
    cin>>N>>M;

    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            scanf("%1d", &B[y][x]);
        }
    }
}

void BFS(int _y, int _x)
{
    queue<tuple<int, int>> queue;  //y,x,count
    V[_y][_x] = 1;
    queue.push({_y,_x});

    while(!queue.empty())
    {
        const auto&[y,x] = queue.front(); queue.pop();

        for(const auto&[dy,dx] : D)
        {
            int ny = dy + y, nx = dx + x;
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(B[ny][nx] == WALL) continue;
            if(V[ny][nx] >= 1) continue;

            V[ny][nx] = V[y][x]+1;
            queue.push({ny,nx});
        }
    }
}

int Solution()
{
    BFS(0,0);
    return V[N-1][M-1];
}

int main()
{
    Input();
    cout<<Solution()<<endl;
}