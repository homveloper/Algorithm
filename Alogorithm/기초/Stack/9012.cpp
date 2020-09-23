#include <iostream>
using namespace std;

class Stack{
char stack[100];
int top;

public:
    Stack(){
        top = -1;
    }

    void push(char value){
        if(top < 100){
            stack[++top];
        }
    }

    bool isEmpty(){
        return top <= -1;
    }

    void pop(){
        --top;
    }
};

bool check(char str[]){

    Stack st;


    for(int j=0; str[j]!='\0'; j++){

        if(str[j] == '('){
            st.push(str[j]);
        }else{
            if(!st.isEmpty())
                st.pop();
            else{
                return false;
            }
        }
    }

    return st.isEmpty();
}


int main(){

    int T;
    char str[101];
    cin>>T;

    for(int i=0; i<T; i++){
        cin>>str;
        cout<<(check(str) ? "YES" : "NO")<<endl;
    }
}  