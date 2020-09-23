/*

    use two stack, s1, s2

    1. char S1.push()
    2. <    S1.pop() -> S2.push()
    3. >    S2.pop() -> S1.push()
    4. -    S1.pop()

    if finished reading string, s2.push(s1.pop()) while s1 is empty
    and cout s2.pop() while s2 is empty.
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N;
    stack<char> s1, s2;
    char str[1000001];

    cin >> N;

    for (int i = 0; i < N; i++)
    {

        cin >> str;
        for (int i = 0; str[i] != '\0'; i++)
        {
            switch (str[i])
            {
            case '<':
                if (!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }

                break;
            case '>':
                if (!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();
                }
                break;
            case '-':
                if (!s1.empty())
                    s1.pop();
                break;
            default:
                s1.push(str[i]);
                break;
            }
        }

        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        while (!s2.empty()){
            cout << s2.top();
            s2.pop();
        }
        cout<<endl;
    }
}