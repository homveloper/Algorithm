#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int COUNT = 4;

int N, M;
vector<vector<int>> G;
vector<bool> V;
bool answer = 0;

void Input()
{
    cin>>N>>M;

    G.resize(N);
    V.resize(N);

    for(int i=0; i<M; i++){
        int p1,p2;
        cin>>p1>>p2;
        G[p1].push_back(p2);
    }
}

void DFS(int depth, int current)
{
    if(depth == COUNT)
    {
        answer = 1;
        return;
    }

    V[current] = true;

    for(auto next : G[current])
    {   
        if(answer) return;
        if(V[next]) continue;
        DFS(depth+1, next);
    }

    V[current] = false;
}

void Solution()
{
    for(int i=0; i<N; i++){
        fill(V.begin(), V.end(), 0);
        DFS(1, i);

        if(answer) break;
    }

    cout<<answer<<endl;
}

int main()
{
    Input();
    Solution();
}