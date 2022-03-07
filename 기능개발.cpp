#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool All(const vector<int>& progresses, int finished)
{
    for(int i=finished; i<progresses.size(); i++){
        if(progresses[i] < 100) return false;
    }
    
    return true;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int finished = 0;
    int lastPublished = 0;
    
    while(!All(progresses, finished))
    {
        for(int i=finished; i<progresses.size(); i++){
            progresses[i] += speeds[i];
            
            if(progresses[finished] >= 100 && progresses[i] >= 100)
            {
                finished++;
                lastPublished++;
            }
        }
        
        if(lastPublished > 0){
            answer.push_back(lastPublished);
            lastPublished = 0;
        }
    }
    return answer;
}

int main()
{
    vector<int> answer = solution({93,30,55},{1,30,5});
    for(auto i : answer)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}