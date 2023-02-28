#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N];

int fun()
{
    char s[10];
    cin >> s;
    if (s[0] == 'f')
    {
        int x = fun();
        return 2 * x - 1;
    }
    else if (s[0] == 'g')
    {
        int x = fun();
        int y = fun();
        return x + 2 * y - 3;
    }
    int n = atoi(s);
    return n;
}

int main()
{
    freopen("p_1_1_5.in", "r", stdin);
    cout << fun();
    return 0;
}
