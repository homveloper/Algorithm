#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;

    cin>>N;

    vector<int> operands(N);
    vector<int> operators;

    for(int i=0; i<N; i++){
        cin>>operands[i];
    }

    for(int i=0; i<4; i++){
        int n;
        cin>> n;

        for(int j=0; j<n; j++){
            operators.push_back(i);
        }
    }


    int min_value = 1'000'000'000;
    int max_value = -1'000'000'000;

    do{
        int result = operands[0];
        int idx = 0;
        
        for(int i=0; i<N-1; i++){
            idx++;
            int op = operators[i];

            if (op == 0)
                result += operands[idx];
            else if(op == 1)
                result -= operands[idx];
            else if(op == 2)
                result *= operands[idx];
            else if(op == 3)
                result /= operands[idx];
        }

        min_value = min(min_value, result);
        max_value = max(max_value, result);

    }while(next_permutation(operators.begin(),operators.end()));

    cout<<max_value<<endl;
    cout<<min_value<<endl;
}