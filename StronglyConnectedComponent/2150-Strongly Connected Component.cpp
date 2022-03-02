#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

const int MAX = 10000;
int V,E;                    // Vertex : 정점의 수, Edge : 간선의 수
int Visited[MAX];           // 방문 여부
int R;                      // SCC의 개수

vector<vector<int>> G;      // Graph : 인접 리스트 방향 그래프
vector<vector<int>> RG;     // Reverse Graph : 인접리스트 역방향 그래프
vector<vector<int>> SCC;    // Strongly Connected Component : 계산된 SCC의 리스트
stack<int> S;               // Stack

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E;

    G.resize(V);
    RG.resize(V);

    for(int i=0; i<E; i++){
        int s,e;
        cin>>s>>e;  s--; e--;

        G[s].push_back(e);
        RG[e].push_back(s);
    }
}

void DFS(int vertex){
    Visited[vertex] = true;
    for(int next : G[vertex]){
        if(Visited[next]) continue;
        DFS(next);
    }
    S.push(vertex);
}

void Func(int vertex, int idx){
    Visited[vertex] = true;
    SCC[idx].push_back(vertex);
    for(int next : RG[vertex]){
        if(Visited[next]) continue;
        Func(next, idx);
    }
}

void Solution(){
    for(int i=0; i<V; i++){
        if(Visited[i]) continue;
        DFS(i);
    }

    memset(Visited,0,sizeof(Visited));

    while(!S.empty()){
        int current = S.top();  S.pop();
        if(Visited[current]) continue;
        SCC.resize(++R);
        Func(current, R-1);
    }

    for(int i=0; i<R; i++){
        sort(SCC[i].begin(),SCC[i].end());
    }
    sort(SCC.begin(), SCC.end(), [](vector<int> a, vector<int> b) -> bool{
        return a[0] < b[0];
    });

    cout<<R<<'\n';

    for(int i=0; i<R; i++){
        for(int e : SCC[i]){
            cout<<e+1<<" ";
        }
        cout<<"-1\n";
    }
}

int main()
{
    Input();
    Solution();
}