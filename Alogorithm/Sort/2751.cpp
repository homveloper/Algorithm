#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int A[], int l, int r){
    int left = l;
    int right = r;

    int pivot = A[(l+r)/2];

    while(left<= right){
        while(A[left] < pivot) left++;
        while(A[right] > pivot) right--;

        if (left<= right){
            swap(A[right],A[left]);
        }
    }
}

int main(){

}