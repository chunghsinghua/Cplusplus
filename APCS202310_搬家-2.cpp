#include <bits/stdc++.h>

using namespace std;

#define N 510
typedef long long ll;

int visit[N][N];

int main()
{
    // freopen("Q_7_8_2.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    string mat[m];
    for (int i = 0; i < m; ++i)
        cin >> mat[i];
    int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
    string d[4] = {"XHLF", "XI7F", "XH7J", "XILJ"}; // EAST,SOUTH, WEST, NORTH
    int mx = -1;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visit[i][j] > 0 || mat[i][j] == '0')
                continue;
            vector<pair<int, int>> que;
            que.push_back({i, j});
            int head = 0;
            visit[i][j] = 1;
            while (head < que.size())
            {
                auto v = que[head++];
                int r = v.first, c = v.second;
                for (int k = 0; k < 4; ++k)
                {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || visit[nr][nc] || mat[nr][nc] == '0')
                        continue;
                    if (d[k].find_first_of(mat[r][c]) != string::npos && d[(k + 2) % 4].find_first_of(mat[nr][nc]) != string::npos)
                    {
                        visit[nr][nc] = 1;
                        que.push_back({nr, nc});
                    }
                }
            }
            mx = max(mx, (int)que.size());
        }
    }
    cout << mx;
    return 0;
}
