#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    vector<vector<int>> dp(n, vector<int>(m));
    for (int j = 0; j < m; ++j)
        dp[0][j] = a[0] * b[j];
    for (int i = 1; i < n; ++i)
        dp[i][0] = a[i] * b[0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
            dp[i][j] = max(0, dp[i - 1][j - 1]) + a[i] * b[j];
    }
    int ans = -100000;
    for (int i = 0; i < n; ++i)
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));

    reverse(b.begin(), b.end());
    for (int j = 0; j < m; ++j)
        dp[0][j] = a[0] * b[j];
    for (int i = 1; i < n; ++i)
        dp[i][0] = a[i] * b[0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
            dp[i][j] = max(0, dp[i - 1][j - 1]) + a[i] * b[j];
    }
    for (int i = 0; i < n; ++i)
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    cout << ans;

    return 0;
}
