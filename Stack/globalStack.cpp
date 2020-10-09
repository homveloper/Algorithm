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
    if(!isEmpty()){
        return stack[top--];
    }
}

int peek(){
    return stack[top];
}

int size(){
    return top + 1;
}
