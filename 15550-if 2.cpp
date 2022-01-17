#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int a = 16777216;
    float b = 16777216 ;
    int c = 16777217;

    cout<<setprecision(40);
    cout<<a<<endl<<b<<endl<<c<<endl;

    /**
     *  a와 b의 자료형이 동일하고 값도 동일
     *  b오 c의 자료형이 동일하고 값도 동일
     *  c와 a의 자료형이 동일하고 값은 다름
     * 
     *  a가 작고 b가 크면
     *      b가 크고 c가 작으면
     *  
    */

   cout<<(a==b)<<endl;
   cout<<(b==c)<<endl;
   cout<<(c!=a)<<endl;

    if (a == b && b == c && c != a) {
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
    return 0;
}