#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_5_3.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m + 1, vector<int>(n, 0));
    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    vector<int> le(n), ri(n);
    for (int i = 1; i <= m; ++i)
    {
        le[0] = dp[i - 1][0] + mat[i][0];
        ri[n - 1] = dp[i - 1][n - 1] + mat[i][n - 1];
        for (int j = 1; j < n; ++j)
            le[j] = max(le[j - 1], dp[i - 1][j]) + mat[i][j];
        for (int j = n - 2; j >= 0; --j)
            ri[j] = max(ri[j + 1], dp[i - 1][j]) + mat[i][j];
        for (int j = 0; j < n; ++j)
            dp[i][j] = max(le[j], ri[j]);
    }
    cout << *max_element(dp[m].begin(), dp[m].end());
    return 0;
}
