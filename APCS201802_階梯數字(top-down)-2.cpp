#include <bits/stdc++.h>

using namespace std;

#define N 20
typedef long long ll;

int dp[N][10][2], d[N];
int fun(int len, int start, int lim)
{
    if (dp[len][start][lim] >= 0)
        return dp[len][start][lim];
    int ret = 0;
    if (lim)
    {
        for (int i = start; i < d[len - 1]; ++i)
            ret += fun(len - 1, i, 0);
        if (d[len - 1] >= start)
            ret += fun(len - 1, d[len - 1], 1);
    }
    else
    {
        for (int i = start; i < 10; ++i)
            ret += fun(len - 1, i, 0);
    }
    return dp[len][start][lim] = ret;
}

int main()
{
    freopen("P_6_19_5.in", "r", stdin);
    ll num;
    cin >> num;
    int mx = 0;
    while (num)
    {
        d[mx++] = num % 10;
        num /= 10;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 1; i < 10; ++i)
        dp[0][i][0] = dp[0][i][1] = 1;
    int ans = 0;
    for (int i = 0; i < d[mx]; ++i)
        ans += fun(mx, i, 0);
    ans += fun(mx, d[mx], 1);
    cout << ans;

    return 0;
}
