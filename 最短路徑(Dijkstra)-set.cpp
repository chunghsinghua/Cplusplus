#include <bits/stdc++.h>

using namespace std;

#define N 10010
typedef long long ll;
#define oo 1000000000

vector<pair<int, int>> adj[N];
int dis[N];
bool visit[N];

int main()
{
    freopen("P_7_9_2.in", "r", stdin);
    int m, n;
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

    set<pair<int, int>> s;
    s.insert({0, 0});
    while (!s.empty())
    {
        auto p = *s.begin();
        s.erase(s.begin());
        int v = p.second;
        if (visit[v])
            continue;

        visit[v] = true;
        for (auto e : adj[v])
        {
            int to = e.first, w = e.second;
            dis[to] = min(dis[to], dis[v] + w);
            s.insert({dis[to], to});
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
