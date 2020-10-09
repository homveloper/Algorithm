#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, value;
    string inst;
    cin>>N;

    queue<int> q;

    for(int i=0; i<N; i++){
        cin>>inst;

        if(inst == "push"){
            cin>>value;
            q.push(value);
        }else if(inst == "front"){
            if(!q.empty())
                cout<<q.front()<<endl;
            else
                cout<<-1<<endl;
        }else if(inst == "back"){
            if(!q.empty())
                cout<<q.back()<<endl;
            else
                cout<<-1<<endl;
        }else if(inst == "size"){
            cout<<q.size()<<endl;
        }else if(inst == "pop"){
            if(!q.empty()){
                cout<<q.front()<<endl;
                q.pop();
            }else{
                cout<< -1<<endl;
            }
        }else if(inst == "empty"){
            cout<<q.empty()<<endl;
        }
    }
}