#include <iostream>
using namespace std;

int N;      // N : 사람의 수
int Q1,Q2;  // Query : 촌수 계산을 할 번호
int M;      // M : 부모와 자식의 관계 수
bool G[101][101];   // Graph : 부모와 자식의 계층 구조(무방향 그래프), 인접행렬
int A=-1;      // Answer : 촌수
bool V[101];

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    cin>>Q1>>Q2;
    cin>>M;

    for(int i=0; i<M; i++){
        int P,C;
        cin>>P>>C;

        G[P][C] = 1;
        G[C][P] = 1;
    }
}

void DFS(int n, int count)
{
    V[n] = 1;

    if(n == Q2)
    {
        A = count;
        return;
    }

    for(int x=1; x<=N; x++){
        if(G[n][x] == 1 && V[x] == 0){
            DFS(x,count+1);
        }
    }
}

int main()
{
    Input();
    DFS(Q1,0);

    cout<<A<<endl;
}

/*

1               4

3 2             5 6
  
  7 8 9
*/
