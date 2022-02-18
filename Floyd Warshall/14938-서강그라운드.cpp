#include <iostream>
#include <algorithm>
using namespace std;

int N, M, R;
int L[100] = {0};
int G[100][100] = {0};
int INF = 100000000;
int result = 0;

void init()
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            G[i][j] = INF;
        }
    }
}

void input(){
    cin >> N >> M >> R;

    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }

    init();

    for (int i = 0; i < R; i++)
    {
        int start, end, weight;

        cin >> start >> end >> weight;

        start--;
        end--;

        G[start][end] = weight;
        G[end][start] = weight;
    }
}
void print()
{
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout<<G[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<result<<endl;
}

void solution()
{
    /*
        플루이드 와샬
    */
    for (int k = 0; k < N; k++)
    {
        G[k][k] = 0;
        for (int s = 0; s < N; s++)
        {
            for (int e = 0; e < N; e++)
            {
                G[s][e] = min(G[s][k] + G[k][e], G[s][e]);
            }
        }
    }

    for(int s = 0; s<N; s++){
        int maxValue = 0;
        for(int e= 0; e<N; e++){
            if (G[s][e] <= M){
                maxValue += L[e];
            }
        }
        result = max(result, maxValue);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();
    print();
}