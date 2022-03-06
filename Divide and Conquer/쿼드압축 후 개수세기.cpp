#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> n_count = {0,0};

bool All(const vector<vector<int>>& arr, int y, int x, int offset)
{
    bool condition = arr[y][x];
    
    for(int i=y; i<y+offset; i++)
        for(int j=x; j<x+offset; j++)
            if(arr[i][j] != condition)
                return false;
    
    return true;
}

void DivideConquer(const vector<vector<int>>& arr, int y, int x, int offset)
{
    if(offset == 1)
    {
        n_count[arr[y][x]]++;
        return;
    }
    
    if(!All(arr,y,x,offset))
    {
        offset /= 2;
        DivideConquer(arr, y,x, offset);
        DivideConquer(arr, y+offset,x, offset);
        DivideConquer(arr, y,x+offset, offset);
        DivideConquer(arr, y+offset,x+offset, offset);        
    }else{
        n_count[arr[y][x]]++;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    DivideConquer(arr,0,0,arr[0].size());
    return n_count;
}

int main()
{
    vector<int> answer = solution({{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 1, 1, 1}});
    for(int i : answer)
        cout<<i<<" ";
    cout<<endl;
}