#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 1000;

int stack[SIZE];
int top = -1;

bool isEmpty(){
    return top == -1;
}
 
bool isFull(){
    return top == SIZE-1;
}

void push(int value){
    if(!isFull())
        stack[++top] = value;
}

int pop(){
    if(!isEmpty())
        return stack[top--];
    
    return -1;
}

int peek(){
    if(!isEmpty())
        return stack[top];

    return -1;
}

int size(){
    return top + 1;
}


int main(){
    int N;
    char inst[1000];
    int value;

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>inst;
        if(strcmp(inst,"push") == 0){
            cin>>value;
            push(value);
        }else if(strcmp(inst,"top") == 0){
            cout<<peek()<<endl;
        }else if(strcmp(inst,"size") == 0){
            cout<<size()<<endl;
        }else if(strcmp(inst,"empty") == 0){
            cout<<isEmpty()<<endl;
        }else if(strcmp(inst,"pop") == 0){
            cout<<pop()<<endl;
        }
    }
}