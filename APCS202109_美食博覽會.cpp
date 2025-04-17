#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n + 1), left(n + 1, 0), last(100001, 0);
    for (int i = 1; i <= n; ++i)
        cin >> vec[i];
    for (int i = 1; i <= n; ++i)
    {
        left[i] = max(left[i - 1], last[vec[i]] + 1);
        last[vec[i]] = i;
    }
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = max(dp[i][j - 1], (j - left[j] + 1) + dp[i - 1][left[j] - 1]);
        }
    }
    cout << dp[k][n];
}
