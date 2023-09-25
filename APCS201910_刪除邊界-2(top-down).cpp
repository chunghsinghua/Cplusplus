#include <bits/stdc++.h>

using namespace std;

#define N 30
typedef long long ll;

int mat[N][N], dp[N][N][N][N];

int cut(int x1, int y1, int x2, int y2)
{
    int ones = 0;
    int zeros = 0;
    for (int i = x1; i <= x2; ++i)
    {
        for (int j = y1; j <= y2; ++j)
        {
            ones += (mat[i][j] == 1);
            zeros += (mat[i][j] == 0);
        }
    }
    return min(ones, zeros);
}
int cost(int x1, int y1, int x2, int y2)
{
    if (dp[x1][y1][x2][y2] >= 0)
        return dp[x1][y1][x2][y2];
    int mcost = min({cut(x1, y1, x1, y2) + cost(x1 + 1, y1, x2, y2),
                     cut(x2, y1, x2, y2) + cost(x1, y1, x2 - 1, y2),
                     cut(x1, y1, x2, y1) + cost(x1, y1 + 1, x2, y2),
                     cut(x1, y2, x2, y2) + cost(x1, y1, x2, y2 - 1)});
    return dp[x1][y1][x2][y2] = mcost;
}

int main()
{
    freopen("P_6_21_5.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    memset(dp, -1, sizeof(dp));
    for (int x1 = 0; x1 < m; ++x1)
    {
        for (int y1 = 0; y1 < n; ++y1)
        {
            for (int x2 = x1; x2 < m; ++x2)
            {
                for (int y2 = y1; y2 < n; ++y2)
                    if ((x1 == x2) || (y1 == y2))
                        dp[x1][y1][x2][y2] = 0;
            }
        }
    }
    cout << cost(0, 0, m - 1, n - 1);
    return 0;
}
