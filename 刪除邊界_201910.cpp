#include <bits/stdc++.h>

using namespace std;

#define N 14
typedef long long ll;

int d[N][N], dp[N][N][N][N];

int cut(int x1, int y1, int x2, int y2)
{
    int ones = 0;
    int zeros = 0;
    for (int i = x1; i <= x2; ++i)
    {
        for (int j = y1; j <= y2; ++j)
        {
            ones += (d[i][j] == 1);
            zeros += (d[i][j] == 0);
        }
    }
    return min(ones, zeros);
}

int main()
{
    freopen("q_1_11_1.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> d[i][j];
    for (int row = 1; row < n; ++row)
    {
        for (int col = 1; col < m; ++col)
        {
            for (int i = 0; i + row < n; ++i)
            {
                for (int j = 0; j + col < m; ++j)
                {
                    dp[i][j][i + row][j + col] = min({dp[i + 1][j][i + row][j + col] + cut(i, j, i, j + col),
                                                      dp[i][j][i + row][j + col - 1] + cut(i, j + col, i + row, j + col),
                                                      dp[i][j][i + row - 1][j + col] + cut(i + row, j, i + row, j + col),
                                                      dp[i][j + 1][i + row][j + col] + cut(i, j, i + row, j)});
                }
            }
        }
    }
    cout << dp[0][0][n - 1][m - 1];
    return 0;
}
