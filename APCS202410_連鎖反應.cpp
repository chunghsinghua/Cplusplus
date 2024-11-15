#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

void bfs(int r, int c, int step, int m, int n, vector<vector<int>> &mat, vector<vector<int>> &dis, vector<pair<int, int>> &que)
{
    int head = 0;
    int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
    for (int i = max(0, r - step); i <= min(m - 1, r + step); ++i)
    {
        for (int j = max(0, c - step); j <= min(n - 1, c + step); ++j)
        {
            dis[i][j] = (mat[i][j] == -1) ? 0 : -1;
        }
    }
    que.push_back({r, c});
    dis[r][c] = 0;
    while (head < que.size())
    {
        int i = que[head].first;
        int j = que[head].second;
        head++;
        if (dis[i][j] >= step)
            continue;
        for (int k = 0; k < 4; ++k)
        {
            int ni = i + dr[k], nj = j + dc[k];
            if (ni >= 0 && nj >= 0 && ni < m && nj < n && dis[ni][nj] == -1)
            {
                dis[ni][nj] = dis[i][j] + 1;
                que.push_back({ni, nj});
            }
        }
    }
}

int dfs(int r, int c, int m, int n, vector<vector<int>> &mat, vector<vector<int>> &dis)
{
    int cnt = 1, nr, nc;
    int x = mat[r][c];
    mat[r][c] = -2;
    if (x == 0)
        return cnt;
    vector<pair<int, int>> que;
    bfs(r, c, x, m, n, mat, dis, que);
    for (auto e : que)
    {
        nr = e.first, nc = e.second;
        if (mat[nr][nc] != -2)
            cnt += dfs(nr, nc, m, n, mat, dis);
    }
    return cnt;
}

int main()
{
    // freopen("Q_3_12_5.in", "r", stdin);
    int m, n, q, r0, c0;
    cin >> m >> n >> q;
    vector<vector<int>> mat(m, vector<int>(n, 0)), d(m, vector<int>(n, 0)), dis(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
            if (mat[i][j] == -2)
                r0 = i, c0 = j;
        }
    }
    vector<pair<int, int>> que;
    bfs(r0, c0, m * n, m, n, mat, d, que);
    int head = 0, cnt = 0, radius = -1;
    while (head < que.size())
    {
        int r = que[head].first, c = que[head].second;
        head++;
        if (mat[r][c] == -2)
            continue;
        cnt += dfs(r, c, m, n, mat, dis);
        if (cnt >= q)
        {
            radius = d[r][c];
            break;
        }
    }
    cout << radius;
    return 0;
}
