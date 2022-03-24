#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
const int MAX = 8;

int N;
int L[MAX];

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=0;i<N;i++){
        L[i] = i+1;
    }
}

void Solution()
{
    do
    {
        for(int i=0; i<N; i++){
            cout<<L[i]<<" ";
        }
        cout<<endl;
    }while(next_permutation(L,L+N));
}

int main()
{
    Input();
    Solution();
}
