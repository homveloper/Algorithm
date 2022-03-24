#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;         // 수열의 크기
int S;         // 조건
vector<int> L; // 수열
int answer = 0;

void Input()
{
    cin >> N >> S;

    L.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }
}

void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        vector<int> V(N, 0);
        fill(V.rbegin(), V.rbegin() + i, 1);

        do
        {
            int sum = 0;
            for(int j=0; j<N; j++)
                if(V[j]) sum += L[j];

            if(sum == S) answer++;
        } while (next_permutation(V.begin(), V.end()));
    }

    cout<<answer<<endl;
}

int main()
{
    Input();
    Solution();
}