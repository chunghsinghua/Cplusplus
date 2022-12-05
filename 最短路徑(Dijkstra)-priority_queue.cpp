#include <bits/stdc++.h>

using namespace std;

#define N 10010
typedef long long ll;
#define oo 1000000000

int dis[N];
bool visit[N];
vector<pair<int, int>> adj[N];

int main()
{
    freopen("P_7_9_3.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 0; i < n; ++i)
        dis[i] = oo;
    dis[0] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto v = pq.top();
        int d = v.second;
        pq.pop();
        if (visit[d])
            continue;
        visit[d] = true;
        for (auto e : adj[d])
        {
            dis[e.first] = min(dis[e.first], dis[d] + e.second);
            pq.push({-dis[e.first], e.first});
        }
    }
    int cnt = 0, mx = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dis[i] < oo)
            mx = max(mx, dis[i]);
        else
        {
            cnt++;
        }
    }
    cout << mx << '\n'
         << cnt;
    return 0;
}
