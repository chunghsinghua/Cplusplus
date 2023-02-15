#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;
int in[110], lc[N], rc[N], w[N], parent[N], deg[N];

int main()
{
    freopen("P_8_5_5.in", "r", stdin);
    int n, m, p;
    cin >> n >> m;
    for (int i = n; i < n * 2; ++i)
        cin >> w[i];
    for (int i = 0; i < m; ++i)
        cin >> in[i];
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> p;
        cin >> lc[p] >> rc[p];
        parent[lc[p]] = parent[rc[p]] = p;
    }
    for (int i = 1; i < n; ++i)
        deg[i] = 2;
    parent[1] = -1;
    queue<int> que;
    for (int i = n; i < n * 2; ++i)
        que.push(i);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        if (v == 1)
            break;
        int p = parent[v];
        w[p] += w[v];
        if (--deg[p] == 0)
            que.push(p);
    }
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
