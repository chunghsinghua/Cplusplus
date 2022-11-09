#include <bits/stdc++.h>

using namespace std;

#define N 10010
typedef long long ll;
#define oo 1000000000

vector<pair<int, int>> adj[N];
int pmn[N], pmx[N], indeg[N];

int main()
{
    freopen("P_7_6_5.in", "r", stdin);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        indeg[v]++;
    }
    for (int i = 0; i < n; ++i)
    {
        pmn[i] = oo;
        pmx[i] = -oo;
    }
    pmn[s] = pmx[s] = 0;

    queue<int> que;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (indeg[i] == 0)
            que.push(i);
    while (!que.empty())
    {
        int v = que.front();
        que.pop(), cnt++;
        for (auto u : adj[v])
        {
            if (pmn[v] < oo)
            {
                pmn[u.first] = min(pmn[u.first], pmn[v] + u.second);
                pmx[u.first] = max(pmx[u.first], pmx[v] + u.second);
            }
            if (--indeg[u.first] == 0)
                que.push(u.first);
        }
    }
    if (cnt != n)
        cout << "not a dag\n";
    if (pmn[t] == oo)
        cout << "No path\nNo path";
    else
    {
        cout << pmn[t] << '\n'
             << pmx[t];
    }

    return 0;
}
