#include <iostream>
#include <vector>
using namespace std;

vector<double> movingAverage(const vector<double> &array, int M);

void main(){
    vector<double> array = {1,2,3,4,5,6,7,8,9,10};

    for (auto const& i : movingAverage(array,3)){
        cout<<i<<" ";
    }

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