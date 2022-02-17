#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Pos
{
    int y,x;
};

vector<Pos> D = {{-1,0},{0,-1},{1,0},{0,1}};
int boundary[100][100] = {0};
int B[100][100] = {0};
bool V[100][100] = {0};
int N, M;


void bfsOutsideAir();
bool melt();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            cin>>B[y][x];
        }
    }

    int time = 0;
    while(true){
        memset(V, 0, sizeof(V));
        memset(boundary, 0, sizeof(boundary));

        bfsOutsideAir();
        bool isMeltedAny = melt();

        if(isMeltedAny){
            time++;
        }else{
            break;
        }
    }

    cout<<time<<endl;
}

bool melt()
{
    bool isMeletedAny = false;

    for(int y=0; y<N; y++)
    {
        for(int x=0; x<M; x++){
            if(boundary[y][x] >= 2){
                B[y][x] = 0;
                isMeletedAny = true;
            }
        }
    }

    return isMeletedAny;
}

void bfsOutsideAir()
{
    queue<Pos> queue;
    queue.push({0,0});

    while(!queue.empty())
    {
        Pos pos = queue.front();    queue.pop();

        if(V[pos.y][pos.x]) continue;
        V[pos.y][pos.x] = true;

        for(auto& [dy,dx] : D)
        {
            int ny = pos.y + dy, nx = pos.x + dx;

            if(0 <= ny && ny < N && 0<=nx && nx < M){
                if(B[ny][nx] == 1){
                    boundary[ny][nx]++;
                }else if(!V[ny][nx]){
                    queue.push({ny,nx});
                }
            }
        }
    }
}