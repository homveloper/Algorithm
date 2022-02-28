#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

const int N = 6;
const int INF = 100000000;

vector<tuple<int, int>> E[N];    // 간선(정점, 비용)
int D[N];                       // 최소 비용

void Dijkstra(int start)
{
    D[start] = 0;
    priority_queue<tuple<int,int>> queue;    // 작은값이 루트 노드

    queue.push(make_pair(start, 0));

    while(!queue.empty())
    {
        auto& [current,_distance] = queue.top();
        // 짧은 값이 먼저오도록 음수화
        int distance = -_distance;
        queue.pop();

        // 최단 거리가 아닌 경우 스킵
        if(D[current] < distance) continue;

        for(int i=0; i<E[current].size(); i++){
            // 선택된 노드의 인접 노드
            auto& [next,_nextDistance] = E[current][i];

            // 선택된 노드의 인접 노드로 거쳐서 가는 비용
            int nextDistance = distance + _nextDistance;

            // 기존의 최소비용 보다 저렴하면 갱신
            if (nextDistance < D[next])
            {
                D[next] = nextDistance;
                queue.push({next, -nextDistance});
            }
        }
    }
}

void Input()
{
    // 연결되지 않은 경우 기본 비용은 무한.
    for(int i=0; i<N; i++){
        D[i] = INF;
    }

    E[0].push_back({1,1});
    E[0].push_back({2,4});
    E[0].push_back({3,0});

    E[1].push_back({0,1});
    E[1].push_back({2,2});
    E[1].push_back({3,1});

    E[2].push_back({0,4});
    E[2].push_back({1,2});
    E[2].push_back({3,2});
    E[2].push_back({4,0});
    E[2].push_back({5,4});

    E[3].push_back({0,0});
    E[3].push_back({1,1});
    E[3].push_back({2,2});
    E[3].push_back({4,0});

    E[4].push_back({2,0});
    E[4].push_back({3,0});
    E[4].push_back({5,1});

    E[5].push_back({2,4});
    E[5].push_back({4,1});
}

void Print()
{
    for(int i=0; i<N; i++){
        cout<<D[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Input();
    Dijkstra(0);
    Print();
} 