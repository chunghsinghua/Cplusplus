#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_4_9_5.in", "r", stdin);
    int m, n, k, r, c;
    cin >> m >> n >> k >> r >> c;
    vector<vector<int>> mat(m + 2, vector<int>(n + 2, -1));
    r++, c++;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    int score = 0, cnt = 0, d = 0;
    while (mat[r][c] > 0)
    {
        score += mat[r][c];
        mat[r][c]--;
        cnt++;
        if (score % k == 0)
            d = (d + 1) % 4;
        for (int j = 0; j < 4; ++j)
        {
            int nr = r, nc = c;
            if (d == 0)
                nc++;
            else if (d == 1)
                nr++;
            else if (d == 2)
                nc--;
            else if (d == 3)
                nr--;

            if (mat[nr][nc] >= 0)
            {
                r = nr, c = nc;
                break;
            }
            else
                d = (d + 1) % 4;
        }
    }
    cout << cnt;
    return 0;
}
