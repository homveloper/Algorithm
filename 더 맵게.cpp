#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> heap(scoville.begin(), scoville.end());
    
    while(heap.size() > 1)
    {
        if(heap.top() >= K) break;
        
        int top1 = heap.top(); heap.pop();
        int top2 = heap.top(); heap.pop();
        
        int newValue = top1 + top2 * 2;
        
        heap.push(newValue);
        answer++;
    }
    
    if(heap.top() < K){
        return -1;
    }
    
    return answer;
}