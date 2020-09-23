#include <iostream>
using namespace std;

class Stack{
char stack[200000];
int top;

public:
    Stack(){
        top = -1;
    }

    void push(char value){
        if(top < 200000){
            stack[++top] = value;
        }
    }

    bool isEmpty(){
        return top == -1;
    }

    char pop(){
        return stack[top--];
    }

    char peak(){
        return stack[top];
    }
};

int main(){
    int N;
    cin>>N;

    char str[200000];

    int result = 0;

    for(int i=0; i<N; i++){
        cin>>str;

        Stack st;
        for(int j=0; str[j] !='\0'; j++){

            if(!st.isEmpty()){
                if(st.peak() == str[j]){
                    st.pop();
                }else{
                    st.push(str[j]);
                }
            }else{
                st.push(str[j]);
            }
        }

        if(st.isEmpty())
            result++;
    }

    cout<<result<<endl;
}