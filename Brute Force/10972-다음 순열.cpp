#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10000;

int N;
int L[MAX];

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>L[i];
    }
}

void Solution()
{   
    if(next_permutation(L,L+N))
    {
        for(int i=0; i<N; i++){
            cout<<L[i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
}

int main()
{
    Input();
    Solution();
}