#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 10000;

string bfs(int start, int end)
{
    queue<pair<int, string>> Q;
    Q.push(make_pair(start, ""));
    bool visited[MAX] = {0};

    visited[start] = true;

    string result = "";
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        string s = Q.front().second;
        Q.pop();
 
        if (x == end) {
            result = s;
            break;
        }
        
        int nx = x * 2;
        if (nx > 9999) nx = nx % 10000;
        if (visited[nx] == false)
        {
            visited[nx] = true;
            Q.push(make_pair(nx, s + "D"));
        }
 
        nx = x - 1;
        if (nx < 0) nx = 9999;
        if (visited[nx] == false)
        {
            visited[nx] = true;
            Q.push(make_pair(nx, s + "S"));
        }
 
        nx = (x % 1000) * 10 + (x / 1000);
        if (visited[nx] == false)
        {
            visited[nx] = true;
            Q.push(make_pair(nx, s + "L"));
        }
 
        nx = (x % 10) * 1000 + (x / 10);
        if (visited[nx] == false)
        {
            visited[nx] = true;
            Q.push(make_pair(nx, s + "R"));
        }
    }

    return result;
}

int main(){
    int T, S, E;
    cin>>T;
    for(int t=0; t<T; t++){
        cin>>S>>E;
        cout<<bfs(S,E)<<endl;
    }
}