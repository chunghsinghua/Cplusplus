#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_12_5.in", "r", stdin);
    int m, n, x;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    vector<pair<int, int>> ret;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int tot = 0;
            x = mat[i][j];
            for (int ni = max(0, i - x); ni <= min(m - 1, i + x); ++ni)
            {
                for (int nj = max(0, j - x); nj <= min(n - 1, j + x); ++nj)
                {
                    if (abs(ni - i) + abs(nj - j) <= x)
                        tot += mat[ni][nj];
                }
            }
            if (tot % 10 == x)
                ret.push_back({i, j});
        }
    }
    cout << ret.size() << '\n';
    for (auto e : ret)
        cout << e.first << ' ' << e.second << '\n';
    return 0;
}
