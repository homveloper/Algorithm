#include <iostream>
#include <vector>
using namespace std;

/*
    n개에서 m개를 고르는 조합

    n : 전체 원소수
    picked : 지금까지 고른 원소들의 번호
    toPick : 앞으로 고를 원소의 수

*/

void print(vector<int> &array)
{
    for (const auto &element : array)
    {
        cout << element << " ";
    }
    cout << endl;
}

void pick(int n, vector<int> &picked, int toPick)
{
    if (toPick == 0)
    {
        for (const auto &element : picked)
        {
            cout << element << " ";
        }
        cout << endl;
        cout<<1;
        return;
    }

    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for (int next = smallest; next < n; ++next)
    {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}

void main()
{
    vector<int> array = {0, 1, 2, 3, 4, 5, 6, 7};
    pick(8, array, 4);
}
