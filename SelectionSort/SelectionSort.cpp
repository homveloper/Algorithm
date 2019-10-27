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

    //선택 정렬
    for(int i=0; i<SIZE; i++){
        int min = INT32_MAX;

        for(int j=i; j<SIZE; j++){
            if(min > arr[j]){
                min = arr[j];
                minIndex = j;
            }
        }
        //현재 위치와 최소값을 swap
        swap(arr[i],arr[minIndex]);
    }

    //정렬 결과
    for(int i=0; i<SIZE; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    system("pause");
}