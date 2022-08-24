#include <bits/stdc++.h>

using namespace std;

#define N 1000010
typedef long long ll;

int d[N];

int fun(int le, int ri)
{
    if (le + 1 >= ri)
        return 0;
    int m = 0, check = INT_MAX;
    for (int i = le + 1; i < ri; ++i)
    {
        int t = fun(le, i) + fun(i, ri);
        if (t < check)
        {
            m = i;
            check = t;
        }
    }
    return (d[ri] - d[le]) + check;
}

int main()
{
    freopen("P_6_17_1.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    d[0] = 0, d[n + 1] = l;
    cout << fun(0, n + 1);
    return 0;
}
