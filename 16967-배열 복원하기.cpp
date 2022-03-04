#include <iostream>
using namespace std;

const int MAX = 601;

int H,W,X,Y;
int B[MAX][MAX];
int result[MAX][MAX];

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>H>>W>>X>>Y;

    for(int y=0; y<H+X; y++){
        for(int x=0; x<W+Y; x++){
            cin>>B[y][x];
        }
    }
}

void Solution()
{
    for(int y=0; y<H; y++){
        for(int x=0; x<W; x++){
            // 두 배열중 하나에 포함되는 경우
            if(y < X || x < Y){
                result[y][x] = B[y][x];
            }
            // 두 배열 모두에 포함되는 경우
            else if(y >= X && x >= Y)
            {
                result[y][x] = B[y][x] - result[y-X][x-Y];
            }
        }   
    }

    for(int y=0; y<H; y++){
        for(int x=0; x<W; x++){
            cout<<result[y][x]<<" ";
        } 
        cout<<endl;
    }
}

int main()
{
    Input();
    Solution();
}

/*

3 3 2 2
1 1 0
1 1 0 
0 0 0


1 1 0 0 0
1 1 0 0 0
0 0 0 0 0 
0 0 0 0 0
0 0 0 0 0

0 0 0 0 0
0 0 0 0 0
0 0 1 1 0
0 0 1 1 0
0 0 0 0 0

=>

1 1 0 0 0
1 1 0 0 0
0 0 1 1 0
0 0 1 1 0
0 0 0 0 0
*/