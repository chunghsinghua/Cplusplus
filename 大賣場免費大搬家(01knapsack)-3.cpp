#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int dp[2][N], wei[N], v[N];

int main()
{
    freopen("P_6_9_3.in", "r", stdin);
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i)
        cin >> wei[i];
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    int idx = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < wei[i]; ++j)
            dp[idx ^ 1][j] = dp[idx][j];
        for (int j = wei[i]; j <= w; ++j)
            dp[idx ^ 1][j] = max(dp[idx][j], dp[idx][j - wei[i]] + v[i]);

        idx ^= 1;
    }
    cout << dp[idx][w];

    return 0;
}
