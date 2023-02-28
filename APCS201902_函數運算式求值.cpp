#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int fun()
{
    string s;
    cin >> s;
    if (s[0] == 'f')
    {
        int x = fun();
        return 2 * x - 3;
    }
    else if (s[0] == 'g')
    {
        int x = fun();
        int y = fun();
        return x * 2 + y - 7;
    }
    else if (s[0] == 'h')
    {
        int x = fun();
        int y = fun();
        int z = fun();
        return 3 * x - 2 * y + z;
    }
    else
        return stoi(s);
}

int main()
{
    // freopen("p_1_1_3.in", "r", stdin);
    cout << fun();
    return 0;
}
