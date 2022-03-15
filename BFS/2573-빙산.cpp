#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Vector2
{
    int y,x;
};

const int EMPTY = 0;
const int MAX = 300;

int N, M;           // 행과 열
int B[MAX][MAX];    // 보드
Vector2 D[] =       // 방향
    {{-1,0},{1,0},{0,-1},{0,1}};  

int V[MAX][MAX];    // 방문 여부
int answer = 0;     // 년도

void Input()
{
    cin>>N>>M;

    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            cin>>B[y][x];
        }
    }
}

// 빙산의 갯수를 카운팅하기 위해 빙산의 위치를 표시
void BFS(Vector2 pos)
{
    queue<Vector2> queue;
    V[pos.y][pos.x] = 1;
    queue.push(pos);

    while(!queue.empty())
    {
        const auto[y,x] = queue.front();
        queue.pop();

        for(const auto&[dy,dx] : D)
        {
            int ny = dy+y, nx = dx + x;

            if(ny < 0 || ny >= N || nx< 0 || nx>=M) continue;
            if(V[ny][nx]) continue;
            if(B[ny][nx] == EMPTY) continue;

            V[ny][nx] =1;
            queue.push({ny,nx});
        }
    }
}

int Count()
{
    int count = 0;

    memset(V,0,sizeof(V));
    for(int y=0; y<N; y++){
        for( int x= 0; x<M; x++){
            if(B[y][x] != EMPTY && !V[y][x]){
                BFS({y,x});
                count++;
            }
        }
    }

    return count;
}

void Melt()
{
    int temp[300][300];
    copy(&B[0][0], &B[0][0]+MAX*MAX, &temp[0][0]);

    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            if(B[y][x] == EMPTY) continue;

            int neighbor = 0;
            for(const auto&[dy,dx] : D)
            {
                int ny = dy+y, nx = dx+x;

                if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
                if(B[ny][nx] == EMPTY){
                    neighbor++;
                }
            }

            temp[y][x] -= neighbor;
            if(temp[y][x] < EMPTY){
                temp[y][x] = EMPTY;
            }
        }
    }

    copy(&temp[0][0], &temp[0][0]+MAX*MAX, &B[0][0]);
}

bool All(bool condition)
{
    for(int y=0; y<N; y++)
        for(int x=0; x<M; x++)
            if(B[y][x] != condition)
                return false;

    return true;
}

void Solution()
{
    while(true){
        // 1. 빙산 개수가 2개 이상이면 종료
        if(Count() >= 2)
        {
            cout<<answer<<endl;
            break;
        }

        // 2.빙산이 다 녹을때까지 분리되지 않으면 0
        if(All(EMPTY))
        {
            cout<<0<<endl;
            break;
        }

        // 2. 한해 증가
        answer++;

        // 3. 빙산 녹이기
        Melt();
    }
}

int main(){
    Input();
    Solution();
}