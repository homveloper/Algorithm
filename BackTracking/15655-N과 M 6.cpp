#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 8;

int N, M;
int L[MAX];
int V[MAX];   

void Input()
{
    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>L[i];
    }

    sort(&L[0], &L[0]+N);
    
}

void Combination(int cnt, int idx)
{
    if(M == cnt){
        for(int i=0; i<M; i++){
            cout<<V[i]<<" ";
        }
        cout<<endl;

        return;
    }

    for(int i=idx; i<N; i++){
        V[cnt] = L[i];
        Combination(cnt+1, i+1);
    }
}

void Solution()
{
    Combination(0,0);
}

int main()
{
    Input();
    Solution();
}