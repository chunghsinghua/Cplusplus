#include <bits/stdc++.h>

using namespace std;

#define N 510
typedef long long ll;

int dis[N][N];

int main()
{
    freopen("P_7_4_5.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    string mat[m + 2];
    string t(n + 2, '1');
    mat[0] = mat[m + 1] = t;
    for (int i = 1; i <= m; ++i)
    {
        mat[i] = "1";
        cin >> t;
        mat[i] += t + "1";
    }
    int ans = 0;
    int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
    memset(dis, -1, sizeof(dis));
    queue<pair<int, int>> que;
    que.push({1, 1});
    dis[1][1] = 0;
    while (!que.empty() && dis[m][n] < 0)
    {
        auto v = que.front();
        que.pop();
        int si = v.first, sj = v.second;
        for (int i = 0; i < 4; ++i)
        {
            int ni = si + dr[i], nj = sj + dc[i];
            while (mat[ni][nj] == '0')
            {
                if (dis[ni][nj] == -1)
                {
                    dis[ni][nj] = dis[si][sj] + 1;
                    que.push({ni, nj});
                }
                ni += dr[i], nj += dc[i];
            }
        }
    }
    if (dis[m][n] > 0)
        cout << dis[m][n] - 1;
    else
        cout << dis[m][n];
    return 0;
}
