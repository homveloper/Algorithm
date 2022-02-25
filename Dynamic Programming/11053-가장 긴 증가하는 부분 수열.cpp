/*
    증가하는 부분 수열

    어떠한 수열의 부분 수열들 중 오름차순인 것, 그리고 가장 긴 증가하는 부분 수열은 
    증가하는 부분 수열중 길이가 가장 긴 것을 의미한다.


    O(N^2) 알고리즘

    dp[i] = i번째 원소를 마지막으로 하는 가장 긴 부분수열의 길이
    dp[i] = 1 ~ i-1까지의 원소들에서, i번째 원소보다 값이 작은것들 중 가장 큰 dp 값 + 1
     
    O(NlogN) 알고리즘

    lower bound 개념을 이용, lower bound란 어떤 정렬된 배열 arr에서 어떠한 값 val이 
    정렬된 상태를 유지하면서 삽입될 수 있는 위치들중 가장 작은 곳을 의미한다.

    예를 들어, [1,2,4,5] 배열에서 3의 lower bound는 2이다.

    그래서 기존 N^2 알고리즘에서 가장 긴 부분수열을 찾는 과정을 이진 탐색을 통해 NlogN으로
    변환 시킬 수 있다.

    1. L이 비어있거나 현재 L의 마지막 원소보다 value가 더 클 경우 L뒤에 length를 추가합니다.
    2. 그렇지 않으면, L에서 value의 lower bound를 찾아, 그 가지를 value로 변경
    3. 
*/


#include <iostream>
#include <algorithm>
using namespace std;

int N;
int L[1000]={0};
int DP[1000]={0};

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

    return *max_element(DP, DP+N);
}

int solution2()
{
    int result = 0;
    int arr[1000] ={0};

    for(int i=0; i<N; i++){
        auto pos = lower_bound(arr, arr+result, L[i]);
        *pos = L[i];

        if(pos == arr + result){
            result++;
        }
    }

    return result;
}

int main()
{
    Input();
    cout<<Solution()<<endl;
}