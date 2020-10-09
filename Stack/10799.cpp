/*

    1. ( count++
    2. ) conut--
        and if () answer += count
            else  answer += 1

*/

#include <iostream>
using namespace std;

char stack[1000010];
int top = -1;

int main(){
    char str[100001];
    int ans = 0;
    int c = 0;
    char prev;

    cin>>str;

    for(int i=0; str[i]!='\0'; i++){

        switch (str[i])
        {
        case '(':
            c++;
            break;
        case ')':
            c--;
            if(prev == '('){
                ans += c;
            }else{
                ans += 1;
            }
            break;
        }

        prev = str[i];
    }

    cout<<ans<<endl;
}