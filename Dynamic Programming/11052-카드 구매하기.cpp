#include <iostream>
#include <numeric>
using namespace std;

const int MAX = 1'001;

int N;
int P[MAX];
int DP[MAX];

void Input()
{
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>P[i];
    }
}

void Solution()
{
    DP[0] = P[0] = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            DP[i] = max(DP[i], DP[i-j] + P[j]);
        }
    }

    cout<<DP[N]<<endl;
}

int main()
{
    Input();
    Solution();

    return 0;
}