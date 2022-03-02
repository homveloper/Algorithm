/*
    1. 8방향 이거나 제자리
    2. 미친 아두이노가 있는곳으로 가면 Lose
    3. 미친 아두이노는 종수의 아두이노로 찾아감
    4. 미친 아두이노가 종수의 아두이노로 가면 Lose
    5. 2개 이상의 미친 아두이노가 같은 칸에 있으면 폭발이 일어남

    종수가 먼저 움직이고 차례로 미친 아두이노가 움직임


    중간에 죽으면 몇번 움직였는지 출력, 그렇지 않으면 현재의 위치를 보드에 표시
*/

// #include <iostream>
// #include <tuple>
// #include <vector>
// #include <set>
// #include <deque>
// #include <algorithm>
// using namespace std;

// const int SIZE = 100;
// const int ENEMY = 2;
// const int PLAYER = 1;
// const int EMPTY = 0;

// struct Vector2D{
//     int y,x;
// };

// struct Object{
//     int type;
//     Vector2D position;
//     bool collision;
// };

// int R,C;                                          // 세로, 가로
// int B[SIZE][SIZE];                                // Board : 보드
// vector<Vector2D> D = {{+1,-1},{+1,+0},{+1,+1},    // Direction(y,x) : 방향 
//                     {+0,-1},{+0,+0},{+0,+1},
//                     {-1,-1},{-1,+0},{-1,+1}};
// Object P;                                       // Player : 종수 아두이노
// deque<Object> E;                               // Enemy : 미친 아두이노
// vector<Vector2D> L;                               // List : 종수가 움직일 방향

// void Input()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin>>R>>C;

//     for(int y=0; y<R; y++){
//         string str; 
//         cin>>str;
//         for(int x=0; x<C; x++){
//             if (str[x] == 'R'){
//                 E.push_back({ENEMY,y,x, false});
//                 B[y][x] = ENEMY;
//             }else if(str[x] == 'I'){
//                 P = {PLAYER,y,x,false};
//                 B[y][x] = PLAYER;
//             }else{
//                 B[y][x] = EMPTY;
//             }
//         }
//     }

//     string str;
//     cin>>str;
//     for(char c : str){
//         L.push_back(D[c - '1']);
//     }
// }

// void Print()
// {
//     for(int y = 0; y<R; y++){
//         for(int x = 0; x<C; x++){
//             cout<<B[y][x]<<" ";
//         }
//         cout<<endl;
//     }

//     // cout<<"P : ("<<P.position.y<<","<<P.position.x<<")"<<endl;

//     // cout<<"E : ";
//     // for(const auto&[position,_] : E){
//     //     cout<<"("<<position.y<<","<<position.x<<") ";
//     // }
//     // cout<<endl;

//     // cout<<"L : ";
//     // for(const auto&[y,x] : L){
//     //     cout<<"("<<y<<","<<x<<") ";
//     // }
//     // cout<<endl;
// }

// void MoveTo(Object& target, Vector2D direction)
// {
//     if(target.collision = B[target.po])
//     B[target.position.y][target.position.x] = EMPTY;

//     auto& [dy, dx] = direction;
//     target.position.y += dy;
//     target.position.x += dx;
//     target.collision =  B[target.position.y][target.position.x] != EMPTY;
//     B[target.position.y][target.position.x] = target.type; 
// }

// bool IsInPlayer(const Vector2D& position){
//     return P.position.y == position.y && P.position.x == position.x;
// }


// void PrintBoard()
// {
//     char result[SIZE][SIZE];

//     for(int y=0; y<R; y++){
//         for(int x=0; x<C; x++){ 
//             result[y][x] = '.';
//         }
//     }

//     result[P.position.y][P.position.x] = 'I';
//     for(const auto&[_,position,__] : E){
//         result[position.y][position.x] = 'R';
//     }

//     cout<<"#################"<<endl;
//     for(int y=0; y<R; y++){
//         for(int x=0; x<C; x++){ 
//             cout<<result[y][x];
//         }
//         cout<<endl;
//     }
// }

// bool Turn(Vector2D direction)
// {
//     // 1. 종수 아두이노 움직이기
//     MoveTo(P, direction);

//     // 2. 미친 아두이노를 만나면 Lose
//     if(P.collision)
//         return false;

//     // 3. 미친 아두이노 움직이기
//     for(auto& enemy : E){
//         const auto& position = enemy.position;
//         int ny = clamp(-(position.y-P.position.y),-1,1);
//         int nx = clamp(-(position.x-P.position.x),-1,1);
//         MoveTo(enemy, {ny,nx});

//         // 종우를 만나면 Lose
//         if(IsInPlayer(enemy.position)) return false;
//     }

//     // 4. 2개 이상인 미친 아두이노 찾아 제거하기
//     for(int i=E.size()-1; i>=0; i--){
//         if(E[i].collision){
//             B[E[i].position.y][E[i].position.x] = EMPTY;
//             E.erase(E.begin()+i);
//         }
//     }

//     PrintBoard();

//     return true;
// }


// void Solution()
// {
//     for(int i=0; i<L.size(); i++){
//         if(Turn(L[i]) == false){
//             cout<<"kraj "<<i+1<<endl;
//             return;
//         }
//     }

//     PrintBoard();
// }
 
// int main()
// {
//     Input();
//     Solution();
// }

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Vector2D{
    int y,x;
};

struct Info{
    Vector2D position;
    bool collision;
};

vector<Vector2D> D = {{+1,-1},{+1,+0},{+1,+1},    // Direction(y,x) : 방향 
                    {+0,-1},{+0,+0},{+0,+1},
                    {-1,-1},{-1,+0},{-1,+1}};

int R,C;                                          // 가로 세로
Vector2D P;                                       // 플레이어 위치
char B[100][100];                                 // 보드
int E_idx[100][100];                              // 보드에 있는 아두이노의 idx
vector<Info> E;                                   // 미친 아두이노
vector<Vector2D> L;                               // 플레이어의 이동 방향

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>R>>C;

    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            cin>>B[y][x];

            if(B[y][x] == 'I'){
                P.y = y;
                P.x = x;
            }else if(B[y][x] == 'R'){
                E.push_back({y,x,false});
            }
        }
    }

    string str;
    cin>>str;
    for(char c : str){
        L.push_back(D[c - '1']);
    }
}

void Print()
{
    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < C; x++)
        {
            cout << B[y][x];
        }
        cout << endl;
    }
}

bool Move()
{
    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            E_idx[y][x] = -1;
        }
    }

    for(int i=0; i<E.size(); i++){
        // 붕괴되지 않은 아두이노
        if(!E[i].collision){

            // 플레이어와 가까운 곳으로 이동
            const auto& [y,x] = E[i].position;

            B[y][x] = '.';

            int ny = clamp(-(y-P.y),-1,1);
            int nx = clamp(-(x-P.x),-1,1);

            // 아두이노 이동
            E[i].position.y += ny;
            E[i].position.x += nx;
            const auto& [y1,x1] = E[i].position;

            // 미친아두이노와 플레이어 충돌
            if(B[y1][x1] == 'I')
                return false;

            // 빈 곳인 경우 해당 위치에 idx 저장
            else if(E_idx[y1][x1] == -1){
                E_idx[y1][x1] = i;
            
            // 미친 아두이노 끼리 충돌
            }else if(E_idx[y1][x1] != -1){
                E[i].collision = true;
                E[E_idx[y1][x1]].collision = true;
            }
        }
    }

    // 4. 붕괴된 아두이노 처리
    for(int i=0; i<E.size(); i++){
        const auto&[y,x] = E[i].position;
        if(E[i].collision)
            B[y][x] = '.';
    }

    for(int i=0; i<E.size(); i++){
        const auto&[y,x] = E[i].position;
        if(!E[i].collision)
            B[y][x] = 'R';
    }
    return true;
}

bool Turn(Vector2D moveDirection){
    // 1. 플레이어 이동
    B[P.y][P.x] = '.';
    P.y += moveDirection.y;
    P.x += moveDirection.x;

    // 2. 미친 아두이노와 부딪혔는지 확인
    if(B[P.y][P.x] == 'R'){
        return false;
    }

    B[P.y][P.x] = 'I';

    // 3. 미친 아두이노 이동
    if(Move() == false){
        return false;
    }

    return true;
}

void Solution()
{
    int result;

    for(int i=0; i<L.size(); i++){
        if(Turn(L[i]) == false){
            cout<<"kraj "<<i+1<<endl;
            return;
        }
    }

    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            cout<<B[y][x];
        }
        cout<<endl;
    }
}


int main()
{
    Input();
    Solution();
}