#include <iostream>
#include <cmath>
using namespace std;

int M,N;

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>M>>N;
}

void Solution()
{
    int sum = 0;
    int minValue = N;

    for(int i=M; i<=N; i++){
        if((sqrt(i) == floor(sqrt(i)))){
            sum += i;
            minValue = min(minValue, i);
        }
    }

    if(sum == 0){
        cout<<-1<<endl;
    }else{
        cout<<sum<<endl;
        cout<<minValue<<endl;
    }
}

int main()
{
    Input();
    Solution();
}