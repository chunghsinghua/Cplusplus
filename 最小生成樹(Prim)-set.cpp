#include <bits/stdc++.h>
using namespace std;

#define N 10010
typedef long long ll;
#define oo 1000000001
vector<pair<int, int>> adj[N];
int d[N], parent[N];
bool visit[N];

int main()
{
    freopen("P_7_12_3.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int s, t, w;
        cin >> s >> t >> w;
        adj[s].push_back({t, w});
        adj[t].push_back({s, w});
    }
    for (int i = 0; i < n; ++i)
        d[i] = oo;
    memset(parent, -1, sizeof(parent));
    int source = 0;
    d[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
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
            if (visit[to])
                continue;
            if (w < d[to])
            {
                d[to] = w;
                parent[to] = v;
                s.insert({d[to], to});
            }
        }
    }

    int cost = 0, cnt = 0;
    for (int i = 0; i < n; ++i)
        if (d[i] < oo)
            cost += d[i];
        else
            cnt++;

    if (cnt)
        cout << -1;
    else
        cout << cost;
    return 0;
}
