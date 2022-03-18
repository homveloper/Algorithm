#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 8;
#define endl '\n'

int N, M;
int L[MAX];
int V[MAX];   

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0; i<N; i++)
        cin>>L[i];

    sort(&L[0], &L[0]+N);
}

void PermutationWithRepetition(int cnt)
{
    if(M == cnt){
        for(int i=0; i<M; i++){
            cout<<V[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=0; i<N; i++){
        V[cnt] = L[i];
        PermutationWithRepetition(cnt+1);
    }
}

void Solution()
{
    PermutationWithRepetition(0);
}

int main()
{
    Input();
    Solution();
}