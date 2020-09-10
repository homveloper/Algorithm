#include <iostream>
using namespace std;

void main(){
    char str[100];

    str[0] = 'a';
    str[1] ='p';
    str[2] = '\0';

    int length = 0;
    for(; str[length] != '\0'; length++);
        
    cout<<length<<endl;
}