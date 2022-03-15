#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int F,  // 건물 층수
    S,  // 강호 위치
    G,  // 스타트링크 위치
    U,  // 내려가는 층수
    D;  // 올라가는 층수

vector<int> L;   // 각 층 마다가 도달할 수 있는 최소 횟수
vector<bool> V;  // 방문 여부

void Input()
{
    cin>>F>>S>>G>>U>>D;
    L.resize(F+1);  fill(L.begin(), L.end(),-1);
    V.resize(F+1);  fill(V.begin(),V.end(),0);
}

void BFS()
{
    queue<int> queue;   // 위치
    queue.push(S);
    V[S] = 1;
    L[S] = 0;
    
    while(!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        if(current == G)
            break;

        if(current+U <= F && !V[current+U]){
            queue.push(current+U);
            L[current+U] = L[current]+1;
            V[current+U] = 1;
        }
        if(current-D > 0 && !V[current-D]){
            queue.push(current-D);
            L[current-D] = L[current]+1;
            V[current-D] = 1;
        }
    }
}

void Solution()
{
    BFS();

    if(L[G] != -1){
        cout<<L[G]<<endl;
    }else{
        cout<<"use the stairs"<<endl;
    }
}

int main()
{
    Input();
    Solution();
}
