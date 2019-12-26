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
    int temp,min;

    //배열 초기화
    for(int i=0;i<SIZE;i++){
        arr[i] = rand()%100+1;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //삽입 정렬
    for(int i=0; i<SIZE; i++){
        int j=i;
        while(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            j--;
        }
    }

    //배열 출력
    for(int i=0;i<SIZE;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    system("pause");
}