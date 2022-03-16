#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Vector2
{
    int y,x;
};

int T;          // Testcase
int N;          // Number of Convenience
int B;          // Bear
int V[100];          // Visited

Vector2 H;      // Home
Vector2 C[100]; // Convenience
Vector2 F;      // Festival

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>T;
}

bool BFS()
{
    memset(V,0,sizeof(V));
    queue<Vector2> queue;

    queue.push(H);

    while(!queue.empty())
    {
        const auto[y,x] = queue.front();
        queue.pop();

        int distance = abs(F.x-x) + abs(F.y-y);
        if(distance <= 1000)
        {
            return true;
        }

        for(int i=0; i<N; i++){
            int distance = abs(C[i].y - y) + abs(C[i].x-x);
            
            if(V[i]) continue;
            if(distance > 1000) continue;

            V[i] = 1;
            queue.push(C[i]);
        }
    }

    return false;
}

void Solution()
{
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        cin >> H.x >> H.y;
        for (int i = 0; i < N; i++)
            cin >> C[i].x >> C[i].y;
        cin >> F.x >> F.y;
        cout << (BFS() ? "happy" : "sad") << endl;
    }
}

int main()
{
    Input();
    Solution();
}