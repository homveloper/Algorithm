#include <iostream>
using namespace std;

int main(){
    int count = 0;
    char str[9];

    for(int i=0; i<8; i++){
        cin>>str;
        for(int j=0; str[j] !='\0'; j++)
            if(j%2 == i%2 && str[j] == 'F'){
                count++;
            }
    }
    cout<<count;
}