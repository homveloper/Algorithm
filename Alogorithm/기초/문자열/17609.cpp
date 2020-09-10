#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(string str){
    bool result = true;

    int length = str.length();
    for(int i=0; i<length/2; i++){
        if(str[i] != str[length-1-i]){
            result = false;
            break;
        }
    }

    return result;
}

int main(){

    int result;
    int T;
    string str;

    cin>>T;

    for(int i=0; i<T; i++){
        
        cin>>str;

        result = 2;

        if(isPalindrome(str)){
            result = 0;
        }else{
            int length = str.length();
            
            for(int j=0; j<length; j++){
                string temp = str;
                temp.erase(temp.begin() + j);

                if(isPalindrome(temp)){
                    result = 1;
                }
            }
        }
        cout<<result;
    }
}