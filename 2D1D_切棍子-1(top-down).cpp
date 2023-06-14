#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int d[N], dp[N][N];

ll fun(int le, int ri)
{
    if (dp[le][ri] >= 0)
        return dp[le][ri];
    ll mn = INT_MAX;
    for (int i = le + 1; i < ri; ++i)
        mn = min(mn, fun(le, i) + fun(i, ri));
    return dp[le][ri] = mn + d[ri] - d[le];
}

int main()
{
    freopen("P_6_17_1.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    d[0] = 0, d[n + 1] = l;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n + 1; ++i)
        dp[i][i + 1] = 0;
    cout << fun(0, n + 1);

    return 0;
}
