#include <iostream>
using namespace std;

char str[1001];

int main(){

    int count = 0;
    cin>>str;

    for(int i=0; str[i] != '\0'; i++){

        if(str[i] == '@')
            count++;

        if(str[i] == '('){
            cout<<count<<" ";
            count = 0;
        }
    }

    cout<<count;
}