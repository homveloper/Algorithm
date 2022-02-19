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
Pos purifier[2];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>R>>C>>T;

    int cnt = 0;

    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            cin>>M[y][x];

            if(M[y][x] == -1){
                purifier[cnt++] = {y,x};
            }
        }
    }
}

template <size_t rows, size_t cols>
void print(int (&array)[rows][cols])
{
    cout<<"##############"<<endl;

    for (size_t i = 0; i < R; ++i)
    {
        for (size_t j = 0; j < C; ++j)
            std::cout << array[i][j] <<" ";
        std::cout << std::endl;
    }
}

int calcParticulates(){

    int sum = 0;

    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            if(M[y][x] > 0 ){
                sum += M[y][x];
            }
        }
    }

    return sum;
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
                if(ny < 0 || ny >=R || nx < 0 || nx >= C || tempM[ny][nx] == -1) continue;
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
    // 위쪽 공기 순환
    int y = purifier[0].y;
    int x = purifier[0].x;

    // ↓
    for(int i=y-1; i>0; i--){
        M[i][x] = M[i-1][x];
    }

    // ←
    for(int i=0; i<C-1; i++){
        M[0][i] = M[0][i+1];
    }

    // ↑
    for(int i=0; i<y; i++){
        M[i][C-1] = M[i+1][C-1];
    }

    // →
    for(int i=C-1; i>x+1; i--){
        M[y][i] = M[y][i-1];
    }
    M[y][x+1] = 0;

    // 아래쪽 공기 순환
    y = purifier[1].y;
    x = purifier[1].x;

    // ↑
    for(int i=y+1; i<R-1; i++){
        M[i][0] = M[i+1][0];
    }

    // ←
    for(int i=0; i<C-1; i++){
        M[R-1][i] = M[R-1][i+1];
    }

    // ↓
    for(int i=R-1; i>y; i--){
        M[i][C-1] = M[i-1][C-1];
    }

    // →
    for(int i=C-1; i>x+1; i--){
        M[y][i] = M[y][i-1];
    }
    M[y][x+1] = 0;
}

int main()
{
    input();

    // spread and purify each second
    for(int t=0; t<T; t++){
        spreadParticulates();
        turnOnAirPurifier();
    }

    cout<<calcParticulates()<<endl;
}