#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 20

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    srand((unsigned int)time(NULL));
    
    int arr[SIZE];
    int temp,minIndex;

    //배열 초기화
    for(int i=0;i<SIZE;i++){
        arr[i] = rand()%100+1;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //버블 정렬 
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE-1-i; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);

    //배열 초기화
    for(int i=0;i<SIZE;i++){
        arr[i] = rand()%100+1;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}