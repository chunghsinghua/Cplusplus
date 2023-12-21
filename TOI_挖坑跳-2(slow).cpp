#include <bits/stdc++.h>

using namespace std;

#define N 510
typedef long long ll;

int d[N * N], p[N * N];
int total = 0, mxsum = 0, mx = 0, totalsum = 0;
int dir[4] = {-1, 1};

int dfs(int v, int root)
{
    p[v] = root;
    int cnt = 1;
    for (int k = 0; k < 4; ++k)
    {
        int u = v + dir[k];
        if (d[u] == 1 && p[u] == -1)
            cnt += dfs(u, root);
    }
    return cnt;
}

void fun(int start, int end)
{
    mx = 0, total = 0;
    memset(p, -1, sizeof(p));
    for (int v = start; v < end; ++v)
    {
        if (d[v] == 1 && p[v] == -1)
        {
            total++;
            p[v] = -dfs(v, v);
            mx = max(mx, -p[v]);
        }
    }
}

int main()
{
    freopen("P_7_10_3.in", "r", stdin);
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> d[i * (n + 2) + j];
    }
    n += 2;
    dir[2] = n, dir[3] = -n;
    int mn = (m + 1) * n;
    fun(n, mn);
    mxsum = mx;
    totalsum = total;
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        int u = i * n + j;
        if (d[u] == 1)
            continue;
        d[u] = 1;
        fun(n, mn);
        mxsum += mx;
        totalsum += total;
    }
    cout << mxsum << '\n'
         << totalsum;

    return 0;
}
