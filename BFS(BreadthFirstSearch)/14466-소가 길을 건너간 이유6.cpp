// #include <iostream>
// #include <vector>
// #include <map>
// #include <queue>
// #include <set>
// #include <cstring>
// using namespace std;

// const int MAX = 10000;        
// int N,K,R;              // 목초지 크기, 소의 수, 길의 수
// map<int,set<int>> G;    // 길의 무방향 그래프  (y=1,x=1,N=3 => 1)
// set<int> C;             // 소 해쉬 값        
// bool V[MAX];            // 소의 방문 여부
// vector<int> D;          // 방향

// int GetHesh(int y, int x, int N){
//     return (y+1)*(N+2) + (x+1);
// }

// void Input()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin>>N>>K>>R;

//     // 방향 설정
//     D.push_back(-1);        // 왼쪽
//     D.push_back(+1);        // 오른쪽
//     D.push_back(-1 * N);    // 위쪽
//     D.push_back(+1 * N);    // 아래쪽

//     for(int i=0; i<R; i++){
//         int y1,x1,y2,x2;
//         cin>>y1>>x1>>y2>>x2;
//         y1--;x1--;y2--;x2--;

//         int p1 = GetHesh(y1,x1,N);
//         int p2 = GetHesh(y2,x2,N);
        
//         G[p1].insert(p2);
//         G[p2].insert(p1);
//     }

//     for(int i=0; i<K; i++){
//         int y,x;
//         cin>>y>>x;
//         y--;x--;
//         C.insert(GetHesh(y,x,N));
//     }
// }

// void BFS(int hesh){
//     memset(V,0,sizeof(V));
//     V[hesh] = 1;
//     queue<int> queue;
//     queue.push(hesh);

//     while(!queue.empty())
//     {
//         int current = queue.front(); queue.pop();

//         for(int d : D)
//         {
//             int next = current + d;
//             if(next < 0 || next >= N*N) continue;
//             if(V[next] == 0){
//                 // 길이 아닌곳이라면? 큐에 넣기
//                 if(G[current].find(next) == G[current].end()){
//                     V[next] =1;
//                     queue.push(next);
//                 }
//             }
//         }
//     }
// }

// int Solution()
// {
//     int count = 0;

//     for(auto iter = C.begin(); iter != C.end(); iter++){
//         BFS(*iter);

//         for(auto j=next(iter); j!=C.end(); j++){
//             if(V[*j] == 0){
//                 count++;
//             }
//         }
//     }

//     return count;
// }

// int main()
// {
//     Input();
//     cout<<Solution()<<endl;

//     for(const auto&[key, value] : G){
//         cout<<key<<" : ";
//         for(auto it = value.begin(); it != value.end(); it++){
//             cout<<*it<<" ";
//         }
//         cout<<endl;
//     }
// }

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

const int MAX = 100;        
int N,K,R;                              // 목초지 크기, 소의 수, 길의 수
bool V[MAX][MAX];                       // 소의 방문 여부
set<tuple<int,int>> G[MAX][MAX];        // 길에 대한 무방향 그래프
set<tuple<int,int>> C;                  // 소의 위치
vector<tuple<int,int>> D = {{-1,0},{0,1},{1,0},{0,-1}}; //방향

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K>>R;

    for(int i=0; i<R; i++){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        y1--;x1--;y2--;x2--;

        G[y1][x1].insert({y2,x2});
        G[y2][x2].insert({y1,x1});
    }

    for(int i=0; i<K; i++){
        int y,x;
        cin>>y>>x;
        y--;x--;
        C.insert({y,x});
    }
}

void BFS(int _y, int _x){
    memset(V,0,sizeof(V));
    V[_y][_x] = 1;
    queue<tuple<int,int>> queue;
    queue.push({_y,_x});

    while(!queue.empty())
    {
        const auto&[y,x] = queue.front(); queue.pop();

        for(const auto&[dy,dx] : D)
        {
            int ny = dy + y, nx = dx + x;
            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;            

            if(V[ny][nx] == 0){
                // 길이 아닌곳이라면? 큐에 넣기
                if(G[y][x].find({ny,nx}) == G[y][x].end()){
                    V[ny][nx] =1;
                    queue.push({ny,nx});
                }
            }
        }
    }
}

int Solution()
{
    int count = 0;

    for(auto iter = C.begin(); iter != C.end(); iter++){
        const auto& [y,x] = *iter;
        BFS(y,x);
        for(auto j=next(iter); j!=C.end(); j++){
            const auto&[ny,nx] = *j;
            if(V[ny][nx] == 0){
                count++;
            }
        }
    }

    return count;
}

int main()
{
    Input();
    cout<<Solution()<<endl;
}