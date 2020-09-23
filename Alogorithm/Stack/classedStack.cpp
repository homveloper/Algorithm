class Stack{
    int stack[2000000];
    int top;

public:
    void push(int value);
    int pop();
    bool isEmpty();
    int size();
    int peek();
};

void Stack::push(int value){
    stack[++top] = value;
}

int Stack::pop(){
    if(!isEmpty())
        return stack[top--];
}

bool Stack::isEmpty(){
    return top == -1;
}

int Stack::size(){
    return top+1;
}

int Stack::peek(){
    return stack[top];
}
