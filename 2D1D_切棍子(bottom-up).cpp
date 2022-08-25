#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int d[N], dp[N][N];

int main()
{
    freopen("P_6_17_1.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> d[i];
    d[0] = 0, d[n + 1] = l;
    for (int len = 2; len < n + 2; ++len)
    {
        for (int i = 0; i + len < n + 2; ++i)
        {
            int k = i + len;
            int mn = LONG_MAX;
            for (int j = i + 1; j < k; ++j)
                mn = min(mn, dp[i][j] + dp[j][k]);
            dp[i][k] = mn + d[k] - d[i];
        }
    }
    cout << dp[0][n + 1];   
    return 0;
}
