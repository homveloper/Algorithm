#include <iostream>
using namespace std;

int main(){
    int T;
    char str[81];

    cin>>T;

    for(int i=0; i<T; i++){

        int score = 0;
        int temp = 0;

        cin>>str;

        for(int j=0; str[j] != '\0'; j++){
            if(str[j] == 'O'){
                temp++;
                score += temp;
            }

            if(str[j] == 'X'){
                temp = 0;
            }
        }
        cout<<score<<endl;
    }
}