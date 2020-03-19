#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

vector<double> movingAverage(const vector<double> &array, int M);

void main(){
    vector<double> array = {1,2,3,4,5,6,7,8,9,10};

    clock_t startTime = clock();

    for (auto const& i : movingAverage(array,3)){
        cout<<i<<" ";
    }

    cout<<endl<<"time : "<<(clock()-startTime) / (CLOCKS_PER_SEC / 1000 )<<endl;

    system("pause");
}

vector<double> movingAverage(const vector<double> &array, int M)
{
    vector<double> ret;

    int N = array.size();

    for (int i = M - 1; i < N; ++i){
        double partialSum = 0;

        for(int j = 0; j<M;++j){
            partialSum += array[i-j];
        }

        ret.push_back(partialSum/M);
    }

    return ret;
}

vector<double> movingAverage2(const vector<double> &array, int M){
    vector<double> ret;

    int N = array.size();
    double partialSum = 0;

    for(int i =0; i< M-1; i++)
        cout<<i<<endl;
}