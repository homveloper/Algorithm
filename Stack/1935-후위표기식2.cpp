#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N;
    char ch;

    string expression;

    stack<int> s;
    cin>>N;
    cin>>expression;

    for(int i=0; i<N; i++){
        ch = (char)getchar();

        cout<<ch<<endl;
    }

}