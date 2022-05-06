#include <bits/stdc++.h>

using namespace std;

#define N 105
typedef long long ll;

int dp[N][N];

int fun(int n, int m)
{
    if (n == 1 || m == 1)
        return 1;
    if (dp[n][m] >= 0)
        return dp[n][m];
    return dp[n][m] = fun(n - 1, m) + fun(n, m - 1);
}

int main()
{
    // freopen("Q_2_10_3.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << fun(n, m);
    return 0;
}
