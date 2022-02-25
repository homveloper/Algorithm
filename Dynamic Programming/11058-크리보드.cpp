/*  
    크리보드

    DP[i] : i번 키보드를 눌렀을 때 A 개수의 최대값

    1.화면에 A를 출력한다.
    DP[i] = DP[i-1]+1

    2.Ctrl-A: 화면을 전체 선택한다
    DP[i] = DP[i-1]
    count = DP[i]

    3.Ctrl-C: 전체 선택한 내용을 버퍼에 복사한다
    DP[i] = DP[i-1]
    buffer = count

    4.Ctrl-V: 버퍼가 비어있지 않은 경우에는 화면에 출력된 문자열의 바로 뒤에 버퍼의 내용을 붙여넣는다.
    DP[i] = DP[i-1] + buffer

    다이나믹프로그래밍의 사용 조건
    
    1. 최적 부분 구조 : 큰 문를 작은 문제로 나눌 수 있다.
    2. 중북되는 부분 문제 : 동일한 작은 문제를 반복적으로 해결한다.

    탑다운과 바텀업

    탑다운(메모이제이션) 방식은 하향식, 바텀업은 상향식이라고 부른다. 


    완전탐색으로 해결 한다면 4가지의 선택을 100번해야 하므로 O(4^100)이다.
    DP를 활용한다면, DP[i]는 i번 째까지의 A의 최대 갯수이다.

    1. A를 1개 붙이기   DP[i] = DP[i-1] + 1
    2. 전체선택, 복사, 붙여넣기 3단계를 하기 즉, DP[i] = DP[i-3] * 2
    그러나 2번 방식은 4단계 전의 값을 복사한다면 DP[i] = DP[i-4] * 3이 될 수 있고 이를 계속진행하다보면
    DP[i] = DP[i-j] * (j-1) , i-j > 0 결론이 나온다.

    그리고 1번의 방식은 i=6일때 까지 최대값을 가질 수 있다.
*/

#include <iostream>
using namespace std;

int N;
long long DP[101];

void Input()
{
    cin>>N;
}

long long Solution()
{
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;
    DP[4] = 4;
    DP[5] = 5;
    DP[6] = 6;

    for(int i=7; i<=N; i++){
        for(int j=3; i-j>0; j++){
            DP[i] = max(DP[i], (j-1) * DP[i-j]);
        }
    }

    return DP[N];
}

int main()
{   
    Input();
    cout<<Solution()<<endl;
}