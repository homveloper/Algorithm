/*
    재귀를 이용한 조합 알고리즘으로, N 명의 사람중 R명을 뽑는 모든 경우의 수를 찾고
    두 팀을 나눴을 때 가장 최소가 되는 값을 저장하여 출력

    NC1 + NC2 + NC3 .. NC(N/2) =  O(2^n)     

    N = 20 => O(2^N) ≒ 백만
*/


#include <iostream>
using namespace std;

const int MAX = 20;
const int START = 1;
const int LINK = 0;

int N;
int B[MAX][MAX];
bool V[MAX];
int answer = 10000000;

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>B[i][j];
        }
    }
}

int Score()
{
    int score1 = 0, score2=0;

    for(int i=0; i<N-1; i++)
    {
        for(int j=i+1; j<N; j++){
            if(V[i] == START && V[j] == START){
                score1 += B[i][j] + B[j][i];
            }
            else if(V[i] == LINK && V[j] == LINK)
            {
                score2 += B[i][j] + B[j][i];
            }
        }   
    }

    return abs(score1 - score2);
}

void Combination(int cnt, int idx)
{
    if(cnt > N/2)
    {
        return;
    }

    if(cnt > 0)
    {
        answer = min(answer, Score());
    }


    for(int i=idx; i<N; i++){
        V[i] = START;
        Combination(cnt + 1, i+1);
        V[i] = LINK;
    }
}

void Solution()
{
    Combination(0,0);
    cout<<answer<<endl;
}

int main()
{
    Input();
    Solution();
}