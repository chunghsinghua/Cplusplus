#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int dp[2][N], wei[N], v[N];

int main()
{
    freopen("P_6_9_5.in", "r", stdin);
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i)
        cin >> wei[i];
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    int from = 0, to = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < wei[i]; ++j)
            dp[to][j] = dp[from][j];
        for (int j = wei[i]; j <= w; ++j)
            dp[to][j] = max(dp[from][j], dp[from][j - wei[i]] + v[i]);

        swap(from, to);
    }
    cout << dp[from][w];

    return 0;
}
