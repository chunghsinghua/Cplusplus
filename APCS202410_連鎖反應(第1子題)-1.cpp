#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int dfs(int r, int c, int m, int n, vector<vector<int>> &mat, vector<vector<int>> &done)
{
    if (r < 0 || c < 0 || r >= m || c >= n || done[r][c])
        return 0;
    int x = mat[r][c];
    int cnt = 1;
    done[r][c] = 1;
    for (int i = r - x; i <= r + x; ++i)
    {
        for (int j = c - x; j <= c + x; ++j)
        {
            if (abs(i - r) + abs(j - c) <= x)
                cnt += dfs(i, j, m, n, mat, done);
        }
    }
    return cnt;
}

int main()
{
    // freopen("Q_3_12_5.in", "r", stdin);
    int m, n, q, r0, c0;
    cin >> m >> n >> q;
    vector<vector<int>> mat(m, vector<int>(n, 0)), done(m, vector<int>(n, 0)), que;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
            if (mat[i][j] == -2)
                r0 = i, c0 = j;
        }
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            que.push_back({abs(i - r0) + abs(j - c0), i, j});
    sort(que.begin(), que.end());
    int cnt = 0, radius, i, j;
    for (auto e : que)
    {
        radius = e[0];
        i = e[1], j = e[2];
        cnt += dfs(i, j, m, n, mat, done);
        if (cnt >= q)
        {
            cout << radius;
            break;
        }
    }
    return 0;
}
