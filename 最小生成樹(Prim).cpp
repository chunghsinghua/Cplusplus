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
    freopen("P_7_12_5.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int s, t, wei;
        cin >> s >> t >> wei;
        adj[s].push_back({t, wei});
        adj[t].push_back({s, wei});
    }
    for (int i = 0; i < n; ++i)
        d[i] = oo;
    memset(parent, -1, sizeof(parent));
    int source = 0;
    d[source] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
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
                pq.push({-d[to], to});
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
