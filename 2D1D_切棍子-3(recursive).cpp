#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int d[N];

ll fun(int le, int ri)
{
    if (le + 1 >= ri)
        return 0;
    ll mn = INT_MAX;
    for (int i = le + 1; i < ri; ++i)
        mn = min(mn, fun(le, i) + fun(i, ri));
    return mn + d[ri] - d[le];
}

int main()
{
    freopen("P_6_17_1.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    d[n + 1] = l;
    cout << fun(0, n + 1);

    return 0;
}
