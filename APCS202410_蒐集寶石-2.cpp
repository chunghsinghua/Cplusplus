#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_12_5.in", "r", stdin);
    int m, n, k, r, c, score = 0, tot = 0, nr, nc, d = 0;
    cin >> m >> n >> k >> r >> c;
    r++, c++;
    vector<vector<int>> mat(m + 2, vector<int>(n + 2, -1));
    int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    while (mat[r][c])
    {
        score += mat[r][c];
        tot++;
        mat[r][c]--;
        if (score % k == 0)
            d = (d + 1) % 4;
        while (1)
        {
            nr = r + dr[d];
            nc = c + dc[d];
            if (mat[nr][nc] != -1)
            {
                r = nr;
                c = nc;
                break;
            }
            d = (d + 1) % 4;
        }
    }
    cout << tot;
    return 0;
}
