#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;
const bool LEFT = 1;
const bool RIGHT = 0;
const char MINERAL = 'x';
const char EMPTY = '.';

int R,C;                        // 세로, 가로
int N;                          // 막대를 던질 횟수
vector<int> H;                  // Height : 막대를 던진 높이
char B[MAX][MAX];               // Board : 보드
vector<tuple<int,int>> D = {{-1,0},{1,0},{0,-1},{0,1}};     // 방향 상 하 좌 우
bool turn;                      // true : 왼쪽, false : 오른쪽
bool V[MAX][MAX];               // Visited : 방문 여부
bool Check[MAX][MAX];               // Check : 클러스터의 미네랄 좌표 저장
vector<tuple<int, int>> Cluster;      // Cluster : 블록이 파괴되어 생성된 클러스터


void Input()
{
    cin>>R>>C;

    for(int y=0;y<R; y++){
        for(int x=0; x<C; x++){
            cin>>B[y][x];
        }
    }

    cin>>N;
    H.resize(N);
    for(int i=0; i<N; i++){
        cin>>H[i];
    }

    turn = true;
}

template <int Rows, int Cols>
void Print(char const (&list)[Rows][Cols]) {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cout <<list[y][x];
        }
        cout << endl;
    }
}

int FindFirst(int y, int turn){

    int x;

    if(turn == LEFT){
        for(x = 0; x<C; x++){
            if(B[y][x] == MINERAL){
                return x;
            }
        }
    }else{
        for(x = C-1; x>=0; x--){
            if(B[y][x] == MINERAL){
                return x;
            }
        }
    }

    return -1;
}

bool BFS(){
    memset(V, 0, sizeof(V));
    memset(Check, 0, sizeof(Check));
    Cluster.clear();

    queue<tuple<int,int>> queue;

    for(int x=0; x<C; x++){
        if(B[R-1][x] == MINERAL){
            queue.push({R-1,x});
            V[R-1][x] = 1;
        }
    }

    while(!queue.empty())
    {
        const auto&[y,x] = queue.front();    queue.pop();

        for(const auto&[dy,dx] : D){
            int ny = dy+y, nx = dx + x;
            if(ny  < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if(V[ny][nx]) continue;

            if(B[ny][nx] == MINERAL){
                V[ny][nx] = 1;
                queue.push({ny,nx});
            }
        }
    }

    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            // 공중에 떠있는 미네랄
            if(B[y][x] == MINERAL && V[y][x] == 0){
                Cluster.push_back({y,x});
                Check[y][x] = 1;
            }
        }
    }

    // 공중에 떠있는 클러스터가 존재하는가?
    return Cluster.size() > 0;
}

void Down()
{
    int minDistance = R+1;

    // 클러스터의 모든 미네랄에 대해서 최대로 내려갈 수 있는 거리를 계산
    for(const auto&[y,x] : Cluster){
        int ny;
        for(ny=y+1; ny<R; ny++){
            // 다른 미네랄이 있으면 거리 갱신
            if(B[ny][x] == MINERAL && Check[ny][x] == 0){
                minDistance = min(minDistance, ny-y-1);
                break;
            }
        }

        // 바닥이면 거리 갱신
        if(ny == R){
            minDistance = min(minDistance, ny-y-1);
        }
    }

    // 맨밑에 있는 클러스터부터 옮겨야 하므로 정렬
    sort(Cluster.begin(), Cluster.end(),greater<>());

    // 해당 거리만큼 모든 클러스터 옮기기
    for(const auto&[y,x] : Cluster){
        B[y][x] = EMPTY;
        B[y+minDistance][x] = MINERAL;        
    }
}

void Throw(int y)
{
    // 1. 현재 턴에 따라 가장 처음 만나는 미네랄 지점을 찾음
    int x = FindFirst(y, turn);

    // 미네랄이 없으면 종료
    if (x == -1){
        turn = !turn;
        return;
    }

    // 2. 미네랄 제거
    B[y][x] = EMPTY;

    // 3. 클러스터 확인
    bool isCluterInAir = BFS();

    if(isCluterInAir){
        // 4. 클러스터 내리기
        Down();
    }

    // 5. 턴 변경
    turn = !turn;
}

void Solution(){
    for(int i=0; i<H.size(); i++){
        Throw(R-H[i]);
    }
    Print(B);
}

int main()
{
    Input();
    Solution();
}

/*
8 8
........
.....xxx
...x.xx.
...xxx..
..xxx...
..x.xxx.
..x...x.
.xxx..x.
5
6 6 4 3 1
*/

/*
12 24
........................
........................
..........xxxxxxxxxxx...
..........x.........x...
..........x.........x...
..........x.........x...
..........x.........x...
..........xxxxxxxxxxx...
..............x.........
..............x.........
..............x.........
..............x.........
1
10
*/

/*
5 6
xxxxxx
..x...
..x...
..x...
.xxx..
3
1 1 1
*/