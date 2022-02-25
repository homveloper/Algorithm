#include <iostream>
#include <algorithm>
using namespace std;

int N;
int L[1000] = {0};
int DP[1000] = {0};
int DPR[1000] = {0};

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }
}

int Solution()
{
    for(int i=0; i<N; i++){
        DP[i] = 1;
        for(int j=0; j<i; j++){
            if(L[i] > L[j] && DP[j]+1 > DP[i]){
                DP[i] = DP[j]+1;
            }
        }
    }

    for(int i=N-1; i>=0; i--){
        DPR[i] = 1;
        for(int j=N-1; j>i; j--){
            if(L[i] > L[j] && DPR[j] + 1 > DPR[i]){
                DPR[i] = DPR[j] + 1;
            }
        }
    }

    int result = 0;
    for(int i=0; i<N; i++){
        result = max(result, DP[i] + DPR[i] - 1);
    }

    return result;
}

int main()
{
    Input();
    cout << Solution() << endl;
}