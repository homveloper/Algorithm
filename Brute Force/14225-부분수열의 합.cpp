#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAX = 2000001;

int N;              // 부분 수열의 크기
vector<int> S;      // 부분 수열
bool R[MAX];    // 자연수

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    S.resize(N);

    for(int i=0; i<N; i++)
    {
        cin>>S[i];
    }
}

void Solution()
{
    for(int i=1; i<=N; i++){
        vector<int> V(N, 0);
        fill(V.rbegin(), V.rbegin()+i,1);

        do
        {
            int sum = 0;

            for(int j=0; j<N; j++){
                if(V[j]) sum += S[j];
            }

            R[sum] = 1;
        }while(next_permutation(V.begin(), V.end()));
    }

    for(int i=1; i<MAX; i++){
        if(!R[i]){
            cout<<i<<endl;
            break;
        }
    }
}

int main()
{
    Input();
    Solution();
}