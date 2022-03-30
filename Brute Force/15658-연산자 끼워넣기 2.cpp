#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 11;
const int N_OPERATOR = 4;
const int ADD = 0;
const int SUB = 1;
const int MUL = 2;
const int DIV = 3;

int N;                  // 수열의 크기
vector<int> A;          // 수열
int O[N_OPERATOR];      // 연산자의 개수
int _min = 1000'000'000;
int _max = -1000'000'000;

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    A.resize(N);
    for(int i=0; i<N; i++){
        cin>>A[i];
    }

    for(int i=0; i<N_OPERATOR; i++){
        cin>>O[i];
    }
}

void DFS(int sum,int cnt)
{
    if(cnt == N)
    {
        _min = min(sum, _min);
        _max = max(sum, _max);
        return;
    }

    for(int i=0; i<4; i++){
        if(O[i] > 0)
        {
            O[i]--;
            switch (i)
            {
            case ADD:
                DFS(sum + A[cnt], cnt+1);
                break;
            case SUB:
                DFS(sum - A[cnt], cnt+1);
                break;
            case MUL:
                DFS(sum * A[cnt], cnt+1);
                break;
            case DIV:
                DFS(sum / A[cnt], cnt+1);
                break;
            }
            O[i]++;
        }
    }
}

void Solution()
{   
    DFS(A[0],1);

    cout<<_max<<endl;
    cout<<_min<<endl;
}

int main()
{
    Input();
    Solution();
}
