#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N][2], dp[N][2];

int main()
{
    freopen("Q_6_4_5.in", "r", stdin);
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i)
        cin >> d[i][0] >> d[i][1];
    dp[0][0] = abs(t - d[0][0]), dp[0][1] = abs(t - d[0][1]);
    for (int i = 1; i < n; ++i)
    {
        dp[i][0] = min(dp[i - 1][0] + abs(d[i - 1][0] - d[i][0]), dp[i - 1][1] + abs(d[i - 1][1] - d[i][0]));
        dp[i][1] = min(dp[i - 1][0] + abs(d[i - 1][0] - d[i][1]), dp[i - 1][1] + abs(d[i - 1][1] - d[i][1]));
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]);
    return 0;
}
