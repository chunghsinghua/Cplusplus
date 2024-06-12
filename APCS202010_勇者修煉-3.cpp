#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_5_3.in", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m + 1, vector<int>(n));
    vector<int> dp(n), le(n), ri(n);
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    for (int i = 1; i <= m; ++i)
    {
        le[0] = dp[0] + mat[i][0];
        for (int j = 1; j < n; ++j)
            le[j] = max(le[j - 1], dp[j]) + mat[i][j];
        ri[n - 1] = dp[n - 1] + mat[i][n - 1];
        for (int j = n - 2; j >= 0; --j)
            ri[j] = max(ri[j + 1], dp[j]) + mat[i][j];
        for (int j = 0; j < n; ++j)
            dp[j] = max(le[j], ri[j]);
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
