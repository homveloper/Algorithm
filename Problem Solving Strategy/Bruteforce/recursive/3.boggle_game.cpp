#include<string>
using namespace std;

const int dx[8] = {-1,-1,-1,1,1,1,0,0};
const int dy[8] = {-1,0,1,-1,0,1,-1,1};

/*
    시간복잡도는 길이 N의 단어에 대해 N-1 단계를 수행하므로
    8^(N-1) = O(8^N)이 된다.
*/
bool hasWord(int x, int y,const string& word){
    // 1. 좌표가 범위 안에 있지 않으면 실패
    if(!inRange(x,y))
        return false;
    
    // 2. 첫 글자가 존재하지 않으면 실패
    if(board[x][y] != word[0])
        return false;

    // 3. 단어 길이가 1이면 성공
    if(word.size() == 1)
        return true;

    // 4. 인접한 여덞 칸을 계산한다.
    for(int direction = 0; direction < 8; ++direction){
        int nextX = x + dx[direction], nextY = y + dy[direction];

        if(hasWord(nextX,nextY,word.substr(1)))
            return true;
    }

    return false;
}