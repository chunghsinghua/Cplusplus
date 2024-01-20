#include <bits/stdc++.h>

using namespace std;

#define N 101
typedef long long ll;

int d[N], dp[N][N], dd[N][N], oo = N * 1000;

int main()
{
    // freopen("Q_7_11_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
        dd[i][i] = d[i];
    }
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 1; i + len - 1 <= n; ++i)
        {
            int j = i + len - 1;
            dp[i][j] = oo;
            for (int k = i; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + abs(dd[i][k] - dd[k + 1][j]));
                dd[i][j] = dd[i][k] + dd[k + 1][j];
            }
        }
    }
    cout << dp[1][n];
    return 0;
}
