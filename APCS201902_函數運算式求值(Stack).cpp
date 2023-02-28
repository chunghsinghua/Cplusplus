#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int main()
{
    // freopen("p_1_1_3.in", "r", stdin);
    string s;
    stack<string> stk1;
    stack<int> stk2;
    while (cin >> s)
        stk1.push(s);
    while (!stk1.empty())
    {
        string v = stk1.top();
        stk1.pop();
        if (v == "f")
        {
            int x = stk2.top();
            stk2.pop();
            stk2.push(2 * x - 3);
        }
        else if (v == "g")
        {
            int x = stk2.top();
            stk2.pop();
            int y = stk2.top();
            stk2.pop();
            stk2.push(2 * x + y - 7);
        }
        else if (v == "h")
        {
            int x = stk2.top();
            stk2.pop();
            int y = stk2.top();
            stk2.pop();
            int z = stk2.top();
            stk2.pop();
            stk2.push(3 * x - 2 * y + z);
        }
        else
            stk2.push(stoi(v));
    }
    cout << stk2.top();
    return 0;
}
