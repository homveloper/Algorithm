#include <iostream>
using namespace std;

/*

줄의 갯수 가 최대 10000000이므로 nlog(n) 복잡도를 가진 정렬 기법으로는 
10000000 * (23 + c)의 시간이 걸리며 이는 3초안에 풀 수 없다. 또한

8Mbyte는 int형 배열 200만개를 생성할 수 있다. 이는 문제에서 제안하는 천만개에는
턱없이 부족하다.

카운팅 정렬을 활용해보자~ 

*/

int main(){

    int arr[20000] = {0};
    // index가 곧 수이다.
    int N;

    cin>>N;

    for(int i=0; i<N; i++){
        int value;
        scanf("%d",&value);
        arr[value]++;
    }

    for(int i=1; i<10001; i++){
        for(int j=0; j<arr[i]; j++){
            printf("%d\n",i);
        }
    }
}