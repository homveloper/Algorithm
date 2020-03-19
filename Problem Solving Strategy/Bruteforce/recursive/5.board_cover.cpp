/*
문제 - 게임판 덮기

H x W 크기의 게임판이 있습니다. 게임판은 검은 칸과 흰 칸으로 구성된 격자 모양을 하고 있습니다. 이 중 모든 흰 칸을 L자 모양의 블록으로 덮으려고 합니다.
이때 블록은 자유롭게 회전이 가능하지만, 서로 겹치거나, 검은 칸을 덮거나, 게임판을 나가면 안됩니다. 게임판이 주어질때 덮을 수 있는 모든 경우의수를 계산하는
프로그램을 작성하세요.

입력
첫줄에는 테스트 케이스의수 C(C<=30)이 주어집니다. 각 테스트 케이스의 첫 줄에는 두 개의 정수 H,W(1<=H,W<=20)가 주어집니다. 다음 H줄에 각 W 글자로 게임판의 모양이 주어집니다.
#은 검은칸, .은 흰칸을 나타냅니다.

출력
각 테스트 케이스마다 덮을 수 있는 모든 경우의 수를 출력합니다.

예제 입력
3
3 7
#.....#
#.....#
##...##
3 7
#.....#
#.....#
##..###
8 10
########
#......#
#......#
#......#
#......#
#......#
#......#
########

예제 출력
0
2
1514
*/

/*

문제해결

일단 블럭은 3칸짜리로 구성되어 있으므로 모든 흰칸의 수가 3의 배수가 되어야 합니다. 그리고 경우의 수를 계산하는 문제이므로 완전탐색을 이용합니다. 
여기서는 재귀 함수를 이용하여 블록하나를 덮을 때 마다 함수를 호출 하는 방식을 이용합시다. 하지만 중복으로 경우의 수를 계산 할 가능성이 있으므로
항상 왼쪽 위칸을 먼저 채우는 식으로 하여 중복으로 계산되는 것을 방지합니다.
*/

#include <vector>
using namespace std;

const int coverType[4][3][2] = {
    { {0,0}, {1,0},{0,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}
};

/*                              ■
    1. ■■   2. ■   3. ■■    4. ■■
       ■       ■■      ■        
*/

bool set(vector<vector<int>>& board, int y, int x, int type, int delta){
    bool ok = true;
    for(int i = 0; i< 3; i++){
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];

        if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
            ok = false;
        else if((board[ny][nx] += delta) > 1)
            ok = false;
    }

    return ok;
}

int cover(vector<vector<int>>& board){
    int y = -1, x = -1;
    for(int i =0; i< board.size(); ++i){
        for(int j = 0; j< board[j].size(); ++j){
            if(board[i][j] == 0){
                y = i;
                x = j;
                break;
            }
        }

        if( y != -1)break;
    }

    if( y==-1) return 1;
    int result = 0;
    for(int type = 0; type < 4; ++type){
        if(set(board,y,x,type,1))
            result += cover(board);
        
        set(board,y,x,type,-1);
    }
    
    return result;
}