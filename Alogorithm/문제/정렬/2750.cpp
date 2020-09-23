#include <iostream>
using namespace std;

int main(){
    int N;

    cin>>N;

    int arr[1000];

    for(int i=0; i<N; i++){
        int value;
        cin>>value;

        arr[i] = value;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i=0; i<N; i++){
        cout<<arr[i]<<endl;
    }

}