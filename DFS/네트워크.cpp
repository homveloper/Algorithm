#include <string>
#include <queue>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>>& computers, int i)
{
    if(!computers[i][i]) return false;

    computers[i][i] = 0;
    for(int j=0; j<computers.size(); j++){
        if(computers[i][j]) DFS(computers, j);
    }

    return true;
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0; i<n; i++){
        if(computers[i][i] && DFS(computers,i))
            answer++; 
    }

    return answer;
}

int main()
{
    solution(3, {{1,1,0},{1,1,0},{0,0,1}});
}