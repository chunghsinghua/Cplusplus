#include <bits/stdc++.h>

using namespace std;

#define N 510
typedef long long ll;

int m, n, k;
int mat[N * N], g[N * N];
int narea, maxarea;
int dir[4] = {1, -1};

int dfs(int v, int root)
{
    g[v] = root;
    int cnt = 1;
    for (int i = 0; i < 4; ++i)
    {
        int u = v + dir[i];
        if (mat[u] && g[u] == -1)
            cnt += dfs(u, v);
    }
    return cnt;
}

int ffind(int x)
{
    if (g[x] < 0)
        return x;
    return g[x] = ffind(g[x]);
}

void funion(int x, int y)
{
    int g1 = ffind(x);
    int g2 = ffind(y);
    if (g1 == g2)
        return;
    maxarea = max(maxarea, -g[g1] - g[g2]);
    narea--;
    if (g[g1] >= g[g2])
    {
        g[g2] += g[g1];
        g[g1] = g2;
    }
    else
    {
        g[g1] += g[g2];
        g[g2] = g1;
    }
}

int main()
{
    freopen("P_7_10_4.in", "r", stdin);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> mat[i * (n + 2) + j];
            g[i * (n + 2) + j] = -1;
        }
    }

    n += 2;
    dir[2] = n, dir[3] = -n;
    int mn = (m + 1) * n;
    for (int v = n; v < mn; ++v)
    {
        if (mat[v] && g[v] == -1)
        {
            g[v] = -dfs(v, v);
            narea++;
            maxarea = max(maxarea, -g[v]);
        }
    }

    int totalarea = narea;
    int totalmax = maxarea;
    while (k--)
    {
        int i, j, v;
        cin >> i >> j;
        v = i * n + j;
        if (mat[v] == 1)
            continue;
        mat[v] = 1;
        narea++;
        for (int i = 0; i < 4; ++i)
        {
            int u = v + dir[i];
            if (mat[u])
                funion(v, u);
        }
        totalarea += narea;
        totalmax += maxarea;
    }

    cout << totalmax << '\n'
         << totalarea;
    return 0;
}
