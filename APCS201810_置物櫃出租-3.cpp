#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int dp[2][N], f[N];

int main()
{
    freopen("Q_6_10_3.in", "r", stdin);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
        cin >> f[i];

    int sum = 0, from = 0, to = 1;
    for (int i = 1; i <= n; ++i)
    {
        sum += f[i];
        for (int j = 1; j <= m - s; ++j)
        {
            if (j < f[i])
                dp[to][j] = dp[from][j];
            else
                dp[to][j] = max(dp[from][j], dp[from][j - f[i]] + f[i]);
        }

        swap(from, to);
    }
    cout << sum - dp[from][m - s];
    return 0;
}
