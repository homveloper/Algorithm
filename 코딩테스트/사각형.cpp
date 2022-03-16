#include <iostream>
using namespace std;

int D[][2] = {{17,19}};     //대각선의 위치
int R=51, C=37;                       //세로, 가로 크기

long long sum[100][100] = {0};

long long Comb(int n, int r)
{
    if(sum[n][r] != 0) return sum[n][r];

    if(n == r || r == 0)
        return 1;
    else
        sum[n][r] = Comb(n-1,r-1) % 1000019 + Comb(n-1,r)%1000019;
        return sum[n][r];
}

long long Solution()
{
    long long answer = 0;

    for(const auto[y,x] : D)
    {
        answer += (Comb(y+x, x) * Comb(R+C-y, R-y))%1000019;
    }

    return answer;
}

int main()
{
    cout<<Solution()<<endl;
}

/*
    (R+C)Comb(C) = (R+C)! / (R! * C!)
    1 * 3!/2! = 6
*/