#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int dp[N][10][2];
vector<int> d;

int fun(int mx, int start, int limit)
{
    if (dp[mx][start][limit] >= 0)
        return dp[mx][start][limit];
    int ret = 0;
    if (limit)
    {
        for (int i = start; i < d[mx - 1]; ++i)
            ret += fun(mx - 1, i, 0);
        if (d[mx - 1] >= start)
            ret += fun(mx - 1, d[mx - 1], 1);
    }
    else
    {
        for (int i = start; i < 10; ++i)
            ret += fun(mx - 1, i, 0);
    }
    return dp[mx][start][limit] = ret;
}

int main()
{
    freopen("P_6_19_2.in", "r", stdin);
    ll num;
    cin >> num;
    while (num)
    {
        d.push_back(num % 10);
        num /= 10;
    }
    int mx = d.size() - 1;
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
