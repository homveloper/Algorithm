#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    vector<int> idx(numbers.size());
    fill(idx.begin(),idx.end(),1);
    
    for(int i=0; i<idx.size(); i++){
        do
        {
            int sum = 0;
            for(int i=0; i<idx.size(); i++){
                sum += idx[i] ? numbers[i] : -numbers[i];
            }
            
            if(sum == target)
                answer++;
        }while(next_permutation(idx.begin(), idx.end()));

        idx[i] = 0;
    }
    
    return answer;
}