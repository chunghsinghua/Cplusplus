#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int d[N], dp[N][N];

int main()
{
    freopen("P_6_17_2.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    d[0] = 0, d[n + 1] = l;
    for (int len = 2; len <= n + 1; ++len)
    {
        for (int i = 0; i + len <= n + 1; ++i)
        {
            int j = i + len, mn = INT_MAX;
            for (int k = i + 1; k < j; ++k)
                mn = min(mn, dp[i][k] + dp[k][j]);
            dp[i][j] = mn + d[j] - d[i];
        }
    }
    cout << dp[0][n + 1];
    return 0;
}
