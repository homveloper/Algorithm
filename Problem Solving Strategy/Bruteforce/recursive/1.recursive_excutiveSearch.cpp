#include <iostream>
using namespace std;

// 1~n들의 합
int sum(int n){
    int value = 0;
    for (int i  = 1; i<=n ; i++)
        value += i;
    return value;
}

int recursiveSum(int n){
    if(n==1) return 1;
    return n+ recursiveSum(n-1); 
}

void main(){
    cout<<sum(10)<<endl;
    cout<<recursiveSum(10)<<endl;
}