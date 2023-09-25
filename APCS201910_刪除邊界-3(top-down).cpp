#include <bits/stdc++.h>

using namespace std;

#define N 30
typedef long long ll;

int dp[N][N][N][N], mat[N][N];

int cut(int si, int sj, int ei, int ej)
{
    int ones = 0, zeros = 0;
    for (int i = si; i <= ei; ++i)
        for (int j = sj; j <= ej; ++j)
        {
            ones += (mat[i][j] == 1);
            zeros += (mat[i][j] == 0);
        }
    return min(ones, zeros);
}

int fun(int si, int sj, int ei, int ej)
{
    if (dp[si][sj][ei][ej] >= 0)
        return dp[si][sj][ei][ej];
    if ((si == ei) || (sj == ej))
        return dp[si][sj][ei][ej] = 0;
    int mn = cut(si, sj, si, ej) + fun(si + 1, sj, ei, ej);
    int tmp = cut(ei, sj, ei, ej) + fun(si, sj, ei - 1, ej);
    if (tmp < mn)
        mn = tmp;
    tmp = cut(si, sj, ei, sj) + fun(si, sj + 1, ei, ej);
    if (tmp < mn)
        mn = tmp;
    tmp = cut(si, ej, ei, ej) + fun(si, sj, ei, ej - 1);
    if (tmp < mn)
        mn = tmp;
    return dp[si][sj][ei][ej] = mn;
}

int main()
{
    freopen("P_6_21_3.in", "r", stdin);
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];

    memset(dp, -1, sizeof(dp));
    cout << fun(0, 0, m - 1, n - 1);
    return 0;
}
