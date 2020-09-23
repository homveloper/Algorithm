#include <iostream>
using namespace std;

class Stack{
int stack[200000];
int top;

public:
    Stack(){
        top = -1;
    }

    void push(int value){
        if(top < 200000){
            stack[++top] = value;
        }
    }

    bool isEmpty(){
        return top == -1;
    }

    int pop(){
        return stack[top--];
    }
};


int main(){
    int K;

    cin>>K; 

    Stack st;

    long long sum = 0;

    for(int i=0; i<K; i++){

        int n;
        cin>>n;

        if(n == 0){
            if(!st.isEmpty())
                st.pop();
        }else{
            st.push(n);
        }
    }

    while(!st.isEmpty()){
        sum += st.pop();
    }

    cout<<sum<<endl;
}