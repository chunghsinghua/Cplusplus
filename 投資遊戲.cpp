#include <bits/stdc++.h>

using namespace std;

#define N 150010
typedef long long ll;

int d[N], dp[22][N];

int main()
{
    // freopen("P_7_6_4.in", "r", stdin);
    int k, n;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    dp[0][0] = d[0];
    for (int i = 1; i < n; ++i)
        dp[0][i] = dp[0][i - 1] < 0 ? d[i] : dp[0][i - 1] + d[i];
    for (int ki = 1; ki <= k; ++ki)
        dp[ki][0] = d[0] < 0 ? 0 : d[0];
    for (int ki = 1; ki <= k; ++ki)
    {
        for (int j = 1; j < n; ++j)
        {
            dp[ki][j] = max(dp[ki - 1][j - 1], dp[ki][j - 1] + d[j]);
        }
    }
    int mx = 0;
    for (int i = 0; i < n; ++i)
        mx = max(mx, dp[k][i]);
    cout << mx;
    return 0;
}
