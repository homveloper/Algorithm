/*
문제
소풍 때 친구인 학생들 끼리 만 두명 씩 짝을 지어 주려고 합니다. 이때 서로 다른 경우의수는 몇인지 계산하세요.

입력
첫줄에는 테스트 케이스의 수 C(C<=50)가 주어집니다. 각 테스트 케이스에는 학생의 수 n(2<=n<=10)과 친구 쌍의 수 m(0<=m<=n(n-1)/2)이 주어집니다.

출력
각 테스트 케이스마다 친구 끼리만 짝지어줄 수 있는 방법의 수를 출력합니다.

*/

#include <iostream>
using namespace std;

int n;
bool areFriends[10][10];
// taken[i] : i번째 학생이 짝을 찾았으면 true 아니면 false
int countParings(bool taken[10]){

    // 짝이 지어지지 않은 학생중 가장 빠른 번호를 찾는다.
    int firstFree = -1;
    for(int i =0; i<n; ++i){
        if(!taken[i]){
            firstFree = i;
            break;
        }
    }

    // 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종요한다.
    if(firstFree == -1) return 1;

    int result = 0;
    // 가장 빠른 번호의 학생과 짝지을 학생을 결정한다.
    for(int pairWith = firstFree + 1; pairWith < n; ++pairWith){
        if(!taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[firstFree] = taken[pairWith] = true;
            result += countParings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }

    return result;
}

void main(){

    int testCase;
    int m;

    cin>>testCase;
    
    for(int i=0; i<testCase; i++){
        cin>>n>>m;

        for(int row = 0; row<10; row++){
            for(int col=0; col<10; col++){
                areFriends[row][col] = false;
            }
        }

        for(int j=0; j<m; j++){
            int friend1, friend2;
            cin>>friend1>>friend2;
            areFriends[friend1][friend2] = true;
        }

        bool taken[10];

        for(int i =0; i<10; i++){
            taken[i] = false;
            cout<<taken[i]<<" ";
        }
        cout<<endl;

        for(int row = 0; row <10; row++){
            for(int col = 0; col <10; col++){
                cout<<areFriends[row][col]<<" ";
            }
            cout<<endl;
        }

        cout<<countParings(taken)<<endl;
    }


    system("pause");
}