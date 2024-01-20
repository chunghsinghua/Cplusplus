#include <bits/stdc++.h>

using namespace std;

#define N 101
typedef long long ll;

int d[N], dp[N][N], oo = N * 1000;

int fun(int le, int ri)
{
    if (dp[le][ri] >= 0)
        return dp[le][ri];
    int mn = oo, tsum = 0, lsum = 0;
    for (int i = le; i <= ri; ++i)
        tsum += d[i];
    for (int i = le; i < ri; ++i)
    {
        lsum += d[i];
        int t = fun(le, i) + fun(i + 1, ri) + abs(tsum - lsum - lsum);
        mn = min(t, mn);
    }
    return dp[le][ri] = mn;
}

int main()
{
    // freopen("Q_7_11_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i)
        dp[i][i] = 0;
    int cost = fun(1, n);
    cout << cost;
    return 0;
}
