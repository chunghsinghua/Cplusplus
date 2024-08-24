#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_3_6_5.in", "r", stdin);
    int r, c, k, m;
    cin >> r >> c >> k >> m;
    vector<vector<int>> mat(r, vector<int>(c, 0));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin >> mat[i][j];
    int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
    int ni, nj;
    while (m--)
    {
        vector<vector<int>> tmp(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (mat[i][j] < 0)
                    continue;
                for (int d = 0; d < 4; ++d)
                {
                    ni = i + dr[d], nj = j + dc[d];
                    if (ni < 0 || nj < 0 || ni >= r || nj >= c || mat[ni][nj] < 0)
                        continue;
                    tmp[ni][nj] += mat[i][j] / k;
                    tmp[i][j] -= mat[i][j] / k;
                }
            }
        }
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                mat[i][j] += tmp[i][j];
    }
    int mn = 1e9, mx = -1;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (mat[i][j] >= 0)
                mn = min(mn, mat[i][j]), mx = max(mx, mat[i][j]);

    cout << mn << '\n'
         << mx;
    return 0;
}
