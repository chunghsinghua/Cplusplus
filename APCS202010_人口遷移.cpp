#include <bits/stdc++.h>

using namespace std;

#define N 60
typedef long long ll;

int mat[N][N], refer[N][N];

int main()
{
    // freopen("P_6_19_3.in", "r", stdin);
    int r, c, k, m;
    cin >> r >> c >> k >> m;
    memset(mat, -1, sizeof(mat));
    memset(refer, -1, sizeof(refer));
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> mat[i][j];

    int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
    while (m--)
    {
        for (int i = 1; i <= r; ++i)
        {
            for (int j = 1; j <= c; ++j)
            {
                if (mat[i][j] >= 0)
                {
                    refer[i][j] = mat[i][j];
                    for (int d = 0; d < 4; ++d)
                    {
                        int ni = i + di[d], nj = j + dj[d];
                        if (mat[ni][nj] >= 0)
                        {
                            refer[i][j] += mat[ni][nj] / k;
                            refer[i][j] -= mat[i][j] / k;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= r; ++i)
            swap(mat[i], refer[i]);
    }
    int mx = 0, mn = 1e9;
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            if (mat[i][j] != -1)
            {
                mx = max(mx, mat[i][j]);
                mn = min(mn, mat[i][j]);
            }
        }
    }
    cout << mn << '\n'
         << mx;
    return 0;
}
