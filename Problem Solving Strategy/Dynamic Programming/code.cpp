#include <iostream>
#include <ctime>
using namespace std;

int dynamicFibonacci(int n);
int fibonacci(int n);


int arr[10000001] = {0};


void main(){

    clock_t start = clock();

    cout<<dynamicFibonacci(10000000)<<endl;

    cout<<(double)(clock() - start)/CLOCKS_PER_SEC<<endl;
}

int fibonacci(int n){

    if( n <= 2)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int dynamicFibonacci(int n){

    if( n <= 2)
        return 1;

    if(arr[n] == 0)
        arr[n] = dynamicFibonacci(n - 1) + dynamicFibonacci(n-2);
    else
        return arr[n];
    
    return dynamicFibonacci(n - 1) + dynamicFibonacci(n - 2);
}

