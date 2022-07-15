#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int dp[2][N], f[N];

int main()
{
    freopen("Q_6_10_1.in", "r", stdin);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
        cin >> f[i];

    int sum = 0, idx = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += f[i];
        for (int j = 1; j <= m - s; ++j)
        {
            if (j < f[i])
                dp[idx ^ 1][j] = dp[idx][j];
            else
                dp[idx ^ 1][j] = max(dp[idx][j], dp[idx][j - f[i]] + f[i]);
        }

        idx ^= 1;
    }
    cout << sum - dp[idx][m - s];
    return 0;
}
