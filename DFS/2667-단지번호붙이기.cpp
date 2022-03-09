#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;                                          // N : 지도의 크기
int B[25][25];                                  // Board : 지도
int V[25][25];                                  // Visited : 방문 여부
const int D[][2] = {{-1,0},{1,0},{0,1},{0,-1}}; // Direction : 방향
vector<int> A;                                  // Answer : 정답
int C = 0;                                      // Count : 집의 수

void Input()
{
    cin>>N;

    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            scanf("%1d", &B[y][x]);
        }
    }
}

void DFS(int y, int x)
{
    V[y][x] = 1;
    C++;

    for(const auto&[dy,dx] : D){
        int ny = y+dy, nx = x + dx;

        if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if(B[ny][nx] == 0) continue;
        if(V[ny][nx] == 1) continue;

        DFS(ny,nx);
    }
}

void Solution(){
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            if(B[y][x] == 1 && V[y][x] == 0){
                C = 0;
                DFS(y,x);
                A.push_back(C);
            }
        }
    }

    sort(A.begin(), A.end());
    cout<<A.size()<<endl;
    for(int i : A) cout<<i<<endl;
}

int main()
{
    Input();
    Solution();
}