#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int N, Q;
vector<tuple<int, int>> G[5000];
bool V[5000];

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>Q;
    for(int i=0; i<N-1; i++){
        int p,q,r;
        cin>>p>>q>>r;   p--;    q--;
        G[p].push_back({q,r});
        G[q].push_back({p,r});
    }


}

void Print()
{
    for(int i=0; i<N; i++)
    {
        cout<<i<<" : ";
        for(auto const& [q,r] : G[i]){
            cout<<"("<<q<<","<<r<<") ";
        }
        cout<<endl;
    }
}

int BFS(int k, int v)
{
    queue<int> queue;
    queue.push(v);
    memset(V, 0, sizeof(V));
    V[v] = 1;

    int cnt = 0;
    while(!queue.empty())
    {
        const int current = queue.front();  queue.pop();
        for(const auto&[next, usado] : G[current])
        {
            if(V[next]) continue;
            if(k<= usado)
            {
                cnt++;
                V[next] = 1;
                queue.push(next);
            }
        }
    }

    return cnt;
}

void Solution()
{
    int k,v;
    for(int i=0; i<Q; i++){
        cin>>k>>v;
        cout<<BFS(k,v-1)<<endl;
    }
}

int main()
{
    Input();
    Solution();
}