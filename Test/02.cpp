#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

struct Vector2D
{
    int y,x;
};

// 우, 하, 우하 
vector<Vector2D> D = {{0,1},{1,0},{1,1},{1,-1}};

int BFS(const vector<string>& board, int h, int w, int n)
{
    int result = 0;
    // y, x, count, direction
    queue<tuple<Vector2D,int,int>> queue;

    for(int y=0; y<h; y++){
        for(int x=0; x<w; x++){
            if(board[y][x] == '1'){
                for(int i=0; i<D.size(); i++){
                    queue.push({{y,x},1,i});
                }
            }
        }
    }

    while(!queue.empty())
    {
        const auto&[vector2, count, dir] = queue.front(); queue.pop();

        if(count == n){
            // const auto&[dy,dx] = D[dir];
            // const auto&[y,x] = vector2;

            // if(y < h-1 && y > 0 && x <w-1 && x > 0){
            //     cout<<y<<","<<x<<" dir : (" <<dy<<","<<dx<<")"<<endl;
            //     if(board[y+dy][x+dx] == '0' && board[y-n*dy][x-n*dx] == '0'){
            //         result++;
            //     }
            // }else if(y == 0){
            //     if(board[y+dy][x+dx] == '0'){
            //         result++;
            //     }
            // }else if(y == h-1){
            //     if(board[y+dy])
            // }
        }

        const auto&[dy, dx] = D[dir];
        int ny = dy+vector2.y, nx = dx+vector2.x;
        if(ny < 0 || ny>= h || nx <0 || nx >= w) continue;

        if(board[ny][nx] == '1'){
            queue.push({{ny,nx},count+1, dir});
        }
    }

    return result;
}

int solution(int h, int w, int n, vector<string> board) {
    return BFS(board,h,w,n);
}

int main()
{
    cout<<solution(7,9,4,{"111100000","000010011","111100011","111110011","111100011","111100010","111100000"})<<endl;
}