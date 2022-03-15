#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

struct Vector2
{
    int y,x;
};

int N;              // 행과 열
int M[100][100];    // 맵
int V[100][100];    // 방문 여부
Vector2 D[] = {{-1,0},{1,0},{0,-1},{0,1}};   // 방향
int answer = 0;     // 결과
int H = 0;          // 최대 높이

void Input()
{
    cin>>N;

    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            cin>>M[y][x];
            H = max(H, M[y][x]);
        }
    }
}

void BFS(Vector2 pos, int h)
{
    queue<Vector2> queue;

    V[pos.y][pos.x] = 1;
    queue.push(pos);

    while(!queue.empty())
    {
        const auto[y,x] = queue.front();
        queue.pop();

        for(const auto[dy,dx] : D)
        {
            int ny = dy+y, nx = dx + x;

            if(ny < 0 || ny>=N || nx<0 || nx>=N) continue;
            if(V[ny][nx]) continue;
            if(M[ny][nx] < h) continue;

            V[ny][nx] = 1;
            queue.push({ny,nx});
        }
    }
}

void Solution()
{
    for (int h = 1; h <= H; h++)
    {
        memset(V,0,sizeof(V));
        int count = 0;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if(M[y][x] >= h && !V[y][x]){
                    BFS({y,x},h);
                    count++;
                }
            }
        }

        answer = max(answer, count);
    }

    cout<<answer<<endl;
}

int main()
{
    Input();
    Solution();
}


