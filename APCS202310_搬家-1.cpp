#include <bits/stdc++.h>

using namespace std;

#define N 510
typedef long long ll;

bool east(char v)
{
    return (v == 'X' || v == 'H' || v == 'L' || v == 'F');
}
bool west(char v)
{
    return (v == 'X' || v == 'H' || v == '7' || v == 'J');
}
bool north(char v)
{
    return (v == 'X' || v == 'I' || v == 'L' || v == 'J');
}
bool south(char v)
{
    return (v == 'X' || v == 'I' || v == '7' || v == 'F');
}

int visit[N][N];

int main()
{
    // freopen("Q_7_8_2.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    string mat[m];
    for (int i = 0; i < m; ++i)
        cin >> mat[i];
    int mx = -1;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (visit[i][j] > 0 || mat[i][j] == '0')
                continue;
            vector<pair<int, int>> que;
            int head = 0;
            visit[i][j] = 1;
            que.push_back({i, j});
            while (head < que.size())
            {
                auto v = que[head++];
                int r = v.first, c = v.second;
                // east
                if (c + 1 < n && east(mat[r][c]) && visit[r][c + 1] <= 0 && west(mat[r][c + 1]))
                {
                    que.push_back({r, c + 1});
                    visit[r][c + 1] = 1;
                }
                // west
                if (c - 1 >= 0 && west(mat[r][c]) && visit[r][c - 1] <= 0 && east(mat[r][c - 1]))
                {
                    que.push_back({r, c - 1});
                    visit[r][c - 1] = 1;
                }
                // south
                if (r + 1 < m && south(mat[r][c]) && visit[r + 1][c] <= 0 && north(mat[r + 1][c]))
                {
                    que.push_back({r + 1, c});
                    visit[r + 1][c] = 1;
                }
                // north
                if (r - 1 >= 0 && north(mat[r][c]) && visit[r - 1][c] <= 0 && south(mat[r - 1][c]))
                {
                    que.push_back({r - 1, c});
                    visit[r - 1][c] = 1;
                }
            }
            mx = max(mx, (int)que.size());
        }
    }
    cout << mx;
    return 0;
}
