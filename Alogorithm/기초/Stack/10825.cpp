#include <iostream>
#include <algorithm>
using namespace std;

struct Student{
    char name[11];

    int kor;
    int eng;
    int mat;

    
    bool operator<(const Student s1){
    }
};


int main(){
    int N;
    cin>>N;


    Student arr[12];

    for(int i=0; i<N; i++){
        scanf("%s %d %d %d",&arr[i].name,&arr[i].kor,&arr[i].eng,&arr[i].mat);
    }

}
