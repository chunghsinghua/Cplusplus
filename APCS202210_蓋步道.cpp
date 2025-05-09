#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

const int oo = 2e6;
vector<int> dr({0, 1, 0, -1}), dc({1, 0, -1, 0});

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
    int ans = -1;
    for (int jump = oo / 2; jump > 0; jump >>= 1)
    {
        while (bfs(n, ans + jump, mat) == oo)
            ans += jump;
    }
    cout << ans + 1 << '\n'
         << bfs(n, ans + 1, mat);
    return 0;
}
