#include <iostream>
using namespace std;

int gcd(int a, int b){
    while (b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main(){
    int T, M, N, x, y;
    cin>>T;

    for(int t=0; t<T; t++){
        cin>>M>>N>>x>>y;

        int year = x % (M+1);
        int _y = x;

        for(int i=0; i<N; i++){
            int ty = _y % N == 0 ? N : _y % N;

            if (ty == y)
                break;
            
            _y = ty + M;
            year += M;
        }

        cout<< ((year > lcm(M,N)) ? -1 : year)<<endl;
    }
}