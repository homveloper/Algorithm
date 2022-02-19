#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos{int y,x;};
vector<Pos> D ={{-1,0},{0,-1},{1,0},{0,1}};
int R,C,T;
int M[50][50];
int tempM[50][50];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>R>>C>>T;

    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            cin>>M[y][x];
        }
    }
}

template <size_t rows, size_t cols>
void print(int (&array)[rows][cols])
{
    for (size_t i = 0; i < R; ++i)
    {
        for (size_t j = 0; j < C; ++j)
            std::cout << array[i][j] <<" ";
        std::cout << std::endl;
    }
}

void spreadParticulates()
{
    copy(&M[0][0], &M[0][0]+50*50, &tempM[0][0]);

    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            // 미세먼지인지 확인
            if(tempM[y][x] <= 0) continue;

            int spreadCount = 0;
            for(const auto& [dy,dx] : D)
            {
                // 좌표 유효성 확인
                int ny = dy+y, nx = dx+x;
                if(ny < 0 || ny >=R || nx < 0 || nx > C || tempM[ny][nx] == -1) continue;
                spreadCount++;

                // 확산되는 양은 정수이며, 다른 미세먼지와 뭉칠 수 있음
                tempM[ny][nx] += M[y][x] / 5;
            }

            tempM[y][x] -= (M[y][x]/5) * spreadCount;
        }
    }

    copy(&tempM[0][0], &tempM[0][0]+50*50, &M[0][0]);
}

void turnOnAirPurifier()
{

}

int main()
{
    input();

    // spread and purify each second
    for(int t=0; t<T; t++){
        spreadParticulates();
        turnOnAirPurifier();
        print(M);
    }
}