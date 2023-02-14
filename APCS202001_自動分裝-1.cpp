#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int w[N], lc[N], rc[N], in[110];

int dfs(int root)
{
    if (w[root] >= 0)
        return w[root];
    return w[root] = dfs(lc[root]) + dfs(rc[root]);
}

int main()
{
    freopen("P_8_5_5.in", "r", stdin);
    memset(w, -1, sizeof(w));
    int n, m;
    cin >> n >> m;
    for (int i = n; i < 2 * n; ++i)
        cin >> w[i];
    for (int i = 0; i < m; ++i)
        cin >> in[i];
    int p, s, t;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> p >> s >> t;
        lc[p] = s, rc[p] = t;
    }
    w[1] = dfs(1);
    for (int i = 0; i < m; ++i)
    {
        int v = 1;
        while (v < n)
        {
            if (w[lc[v]] <= w[rc[v]])
                v = lc[v];
            else
                v = rc[v];
            w[v] += in[i];
        }
        if (i > 0)
            cout << ' ';
        cout << v;
    }
    return 0;
}
