#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char str[]){
    bool result = true;

    int length = strlen(str);
    for(int i=0; i<length/2; i++){
        if(str[i] != str[length-1-i]){
            result = false;
            break;
        }
    }

    return result;
}

int main(){
    char str[101];

    cin>>str;

    cout<<isPalindrome(str);
}