#include <iostream>
using namespace std;

int main(){
    int length;
    char str[101];

    cin>>length;
    cin>>str;

    for(int i=0; i<length; i++){
        if(str[i] == '?'){
            if(str[length-1-i] != '?'){
                str[i] = str[length-1-i];
            }else{
                str[i] = 'a';
                str[length-1-i] = 'a';
            }
        }
    }
    cout<<str;
}