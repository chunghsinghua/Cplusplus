#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int dp[100][N], f[N];

int main()
{
    freopen("Q_6_10_5.in", "r", stdin);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
        cin >> f[i];

    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += f[i];
        for (int j = 1; j <= m - s; ++j)
        {
            if (j < f[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - f[i]] + f[i]);
        }
    }
    cout << sum - dp[n][m - s];
    return 0;
}
