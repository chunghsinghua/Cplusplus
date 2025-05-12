#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_6_7_5.in", "r", stdin);
    int n, m, v, u, w;
    cin >> n >> m;
    const int oo = 1e9 + 1;
    vector<int> d(n, oo);
    vector<bool> done(n, false);
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for (int i = 0; i < m; ++i)
    {
        cin >> v >> u >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }
    priority_queue<pair<int, int>> pq;
    d[0] = 0;
    pq.push({0, 0}); //{-w, vertex};
    while (!pq.empty())
    {
        auto vv = pq.top();
        pq.pop();
        v = vv.second;
        if (done[v])
            continue;
        done[v] = true;
        for (auto e : adj[v])
        {
            u = e.first, w = e.second;
            if (d[v] + w < d[u])
            {
                d[u] = d[v] + w;
                pq.push({-d[u], u});
            }
        }
    }
    int mx = 0, cnt = 0;
    for (int e : d)
    {
        if (e == oo)
            cnt++;
        else
            mx = max(mx, e);
    }
    cout << mx << '\n'
         << cnt;
    return 0;
}
