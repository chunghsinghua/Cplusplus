#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

const int oo = 2e6;
vector<int> dr({0, 1, 0, -1}), dc({1, 0, -1, 0});

int prim(int n, vector<vector<int>> &mat)
{
    priority_queue<vector<int>> pq;
    vector<vector<bool>> visit(n + 2, vector<bool>(n + 2, false));
    pq.push({0, 1, 1});
    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        int vr = v[1], vc = v[2];
        if (vr == n && vc == n)
            return v[0];
        if (visit[vr][vc])
            continue;
        visit[vr][vc] = true;
        for (int i = 0; i < 4; ++i)
        {
            int nr = vr + dr[i], nc = vc + dc[i];
            if (visit[nr][nc])
                continue;
            pq.push({min(v[0], -abs(mat[nr][nc] - mat[vr][vc])), nr, nc});
        }
    }
    return -1;
}

int bfs(int n, int slope, vector<vector<int>> &mat)
{
    vector<vector<int>> d(n + 2, vector<int>(n + 2, oo));
    d[1][1] = 0;
    queue<pair<int, int>> que;
    que.push({1, 1});
    while (!que.empty() && d[n][n] == oo)
    {
        auto v = que.front();
        int vr = v.first, vc = v.second;
        que.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nr = vr + dr[i], nc = vc + dc[i];
            if (d[nr][nc] == oo && abs(mat[vr][vc] - mat[nr][nc]) <= slope)
            {
                d[nr][nc] = d[vr][vc] + 1;
                que.push({nr, nc});
            }
        }
    }
    return d[n][n];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n + 2, vector<int>(n + 2));
    for (int i = 0; i <= n + 1; ++i)
    {
        mat[0][i] = oo;
        mat[i][0] = oo;
        mat[n + 1][i] = oo;
        mat[i][n + 1] = oo;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    int ans = -prim(n, mat);
    cout << ans << '\n'
         << bfs(n, ans, mat);

    return 0;
}
