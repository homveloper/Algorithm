#include <iostream>
using namespace std;

const int IDX_OFFSET = 1000;
const int MAX = 2001;

int N;                  // 수의 개수
int L[MAX] = {0};      // 1번이라도 나온 결과라면 1로 저장 -1000 부터 0번째 인덱스

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
}

void Solution()
{
    for(int i=0; i<N; i++){
        int n;  cin>>n;
        L[n+IDX_OFFSET] = 1;
    }

    for(int i=0; i<MAX; i++){
        if(L[i]) cout<<i-IDX_OFFSET<<" ";
    }
    cout<<endl;
}

int main()
{
    Input();
    Solution();
}