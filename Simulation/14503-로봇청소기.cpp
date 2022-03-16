/*
    1. 현재 위치 청소

    2. 현재 위치에서 현재 방향을 기준으로 왼쪽 방향으로 차례대로 인접칸을 탐색
        - 왼쪽 방향에 청소하지 않으면 그곳으로 회전한 뒤 이동, 그 후 1번 반복
        - 왼쪽 방향에 청소할 공간이 없다면 그 방향으로 회전하고 2번 반복
        - 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 방라보는 방향을 유치한 채로 한 칸 후진을 하고 2번 반복
        - 네 방향 모두 청소가 이미 되어있거나 뒤쪽 방향이 벽이라 후진할 수 없는 경우에는 작동을 멈춤

    이미 청소된 칸은 가지 않음

*/


#include <iostream>
using namespace std;

struct Vector2
{
    int y,x;
};

const int WALL = 1;
const int EMPTY = 0;
const int CLEAR = -1;

int N,M;        // 세로 가로
Vector2 R;      // 현재 로봇 위치
Vector2 RD;     // 현재 로봇 방향
Vector2 D[] = 
    {{-1,0},    // 북쪽
    {0,1},      // 동쪽
    {1,0},      // 남쪽
    {0,-1}};    // 서쪽
int B[50][50];  // 보드
int answer = 0;

void Input()
{
    cin>>N>>M;
    cin>>R.y>>R.x;

    int dir;
    cin>>dir;
    RD = D[dir];

    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            cin>>B[y][x];
        }
    }
}

Vector2 GetNextDir(Vector2 dir)
{
    if(dir.y == -1 && dir.x == 0){        //북쪽
        return D[3];
    }else if(dir.y == 1 && dir.x == 0){   //남쪽
        return D[1];
    }else if(dir.y == 0 && dir.x == 1){   //동쪽
        return D[0];
    }else{                              //서쪽
        return D[2];
    }
}

void Solution()
{
    while(true)
    {
        // 1. 현재 위치 청소
        if(B[R.y][R.x] == EMPTY){
            answer++;
        }
        B[R.y][R.x] = CLEAR;

        // 2. 인접칸 탐색
        // 2-1. 현재 위치 기준 왼쪽 방향 선정
        bool any = false;
        Vector2 nextDir = GetNextDir(RD);
        for(int i=0; i<4; i++){
            int ny = R.y + nextDir.y;
            int nx = R.x + nextDir.x;

            if(B[ny][nx] == EMPTY){
                R = {ny,nx};
                RD = nextDir;
                any = true;
                break;
            }
            nextDir = GetNextDir(nextDir);
        }

        // 2-2. 네 방향 모두 청소가 이미 되어있거나 벽인 경우 바라보는 방향을 유치한 채로 한칸 후진
        if(any == false)
        {
            R.y -= RD.y;
            R.x -= RD.x;
        }

        // 2-3. 후진 한 곳이 벽이면 종료
        if(B[R.y][R.x] == WALL)
        {
            break;
        }
    }

    cout<<answer<<endl;
}

int main()
{
    Input();
    Solution();
}