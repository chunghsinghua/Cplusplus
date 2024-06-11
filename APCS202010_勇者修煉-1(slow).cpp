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
    vector<vector<int>> mat(m + 1, vector<int>(n, 0));
    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            dp[i][j] = dp[i - 1][j] + mat[i][j];
            int t;
            for (int k = 0; k < j; ++k)
            {
                t = dp[i - 1][k];
                for (int kk = k; kk <= j; ++kk)
                    t += mat[i][kk];
                dp[i][j] = max(dp[i][j], t);
            }
            for (int k = n - 1; k > j; --k)
            {
                t = dp[i - 1][k];
                for (int kk = k; kk >= j; --kk)
                    t += mat[i][kk];
                dp[i][j] = max(dp[i][j], t);
            }
        }
    }
    cout << *max_element(dp[m].begin(), dp[m].end());
    return 0;
}
