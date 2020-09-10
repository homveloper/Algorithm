#include <iostream>
using namespace std;

char str[1000001];
int Count[26];
char c;

int main(){

    int maxCount = 0;

    cin>>str;

    for(int i=0; str[i]!='\0'; i++){
        if(str[i] >= 'a')
            str[i] -= 'a' - 'A';
    }

    for(int i=0; str[i]!='\0'; i++){
        Count[str[i] - 'A']++;

        if(Count[str[i]-'A'] > maxCount){
            maxCount = Count[str[i]-'A'];
            c = str[i];
        }else if(Count[str[i]-'A'] == maxCount)
            c = '?';
    }
    cout<<c<<endl;
}