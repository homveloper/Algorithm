#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;

const int SIZE = 1000;

vector<tuple<int,int>> G[SIZE];     // 간선(정점, 비용)
int INF = 100000000;                // 최대값
int D[SIZE];                        // 최소 비용
int N,M;                            // 도시 개수, 버스 개수
int S,E;                            // 출발점, 도착점
int P[SIZE] = {0};                  // 인덱스 : 도착점, 값 : 출발점

void Input()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    int s,e,w;
    for(int i=0; i<M; i++){
        cin>>s>>e>>w;
        G[s-1].push_back({e-1,w});
    }

    cin>>S>>E;
    S-=1;   E-=1;

    for(int i=0; i<N; i++){
        D[i] = INF;
    }
}

void Print()
{
    cout<<D[E]<<endl;

    stack<int> s;
    int idx = E;

    while(idx != S){
        s.push(idx);
        idx = P[idx];
    }
    s.push(S);

    cout<<s.size()<<endl;

    while(!s.empty())
    {
        cout<<s.top() + 1 <<" ";
        s.pop();
    }
    cout<<endl;
}

void Dijkstra(int start)
{
    D[start] = 0;
    priority_queue<tuple<int,int>> queue;
    queue.push({start,0});

    while(!queue.empty())
    {
        int current, distance;  tie(current,distance) = queue.top();
        distance *= -1;
        queue.pop();

        if(D[current] < distance) continue;

        for(int i=0; i<G[current].size(); i++){
            int next, nextDistance; tie(next,nextDistance) = G[current][i]; 
            nextDistance += distance;

            if(nextDistance < D[next]){
                D[next] = nextDistance;
                queue.push({next, -nextDistance});
                P[next] = current;
            }
        }
    }
}

int main(){
    Input();
    Dijkstra(S);
    Print();
}