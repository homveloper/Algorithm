#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <algorithm>
using namespace std;

const int WHITE = 0;
const int RED = 1;
const int BLUE = 2;

struct Horse
{
    int y,x,d;
    bool isBottom;
};

const int MAX = 12;
const int HORSE_MAX = 10;

int N, K;                       // 체스판 크기, 말의 개수
int B[12][12];                  // 체스판
vector<Horse> H;                // 말들의 위치 및 스택형태로 각 말은 이동방향을 가짐
int turn = 0;
vector<int> HorseMap[HORSE_MAX][HORSE_MAX];
vector<tuple<int,int>> D = {{0,1},{0,-1},{-1,0},{1,0}}; // 이동방향 1,2,3,4 = 우:좌:상:하

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;

    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            cin>>B[y][x];
        }
    }

    for(int i=0; i<K; i++){
        int y,x,d;
        cin>>y,x,d;
        y--; x--;   d--;
        HorseMap[y][x].push_back(i);
        H.push_back({y,x,d,true});
    }
}

bool IsEnd()
{

}

void TurnStart()
{
    for (int i = 0; i < H.size(); i++){

        if (!H[i].isBottom) continue;

        const auto &[dy,dx] = D[H[i].d];
        int ny = dy + H[i].y, nx = dx + H[i].x;

        // 맵을 벗어나는 경우
        if (ny < 0 || ny >= N || nx < 0 || ny >= N){

        }
        // 흰색인 경우
        else if (B[ny][nx] == WHITE){
            if(HorseMap[ny][nx].size() > 0) H[HorseMap[ny][nx][0]]
        }
        else if (B[ny][nx] == BLUE){

        }
        else if (B[ny][nx] == RED){
            
        }
    }
}

void Solution()
{

}

int main()
{

}