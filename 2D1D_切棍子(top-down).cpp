#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int d[N], dp[N][N];

int fun(int le, int ri)
{
    if (dp[le][ri] >= 0)
        return dp[le][ri];
    int mn = INT_MAX;
    for (int i = le + 1; i < ri; ++i)
        mn = min(mn, fun(le, i) + fun(i, ri));
    mn += d[ri] - d[le];
    return dp[le][ri] = mn;
}

int main()
{
    freopen("P_6_17_5.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    d[0] = 0, d[n + 1] = l;
    for (int i = 0; i < n + 2; ++i)
        for (int j = i + 2; j < n + 2; ++j)
            dp[i][j] = -1;
    cout << fun(0, n + 1);
    return 0;
}
