#include <bits/stdc++.h>

using namespace std;

#define N 10010
typedef long long ll;
#define oo 1000000000

int d[N], parent[N];
bool visit[N];

int main()
{
    // freopen("P_7_9_5.in", "r", stdin);
    int n, m, u, v, w;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < n; ++i)
        d[i] = oo;
    memset(parent, -1, sizeof(parent));
    d[0] = 0;
    while (1)
    {
        int v = -1;
        int mn = oo;
        for (int i = 0; i < n; ++i)
        {
            if (!visit[i] && d[i] < mn)
            {
                v = i;
                mn = d[i];
            }
        }
        if (v < 0)
            break;
        visit[v] = true;
        for (auto e : adj[v])
        {
            if (d[v] + e.second < d[e.first])
            {
                d[e.first] = d[v] + e.second;
                parent[e.first] = v;
            }
        }
    }

    int mx = -1, cnt = 0, far;
    for (int i = 0; i < n; ++i)
    {
        if (d[i] < oo)
        {
            if (d[i] > mx)
            {
                mx = d[i];
                far = i;
            }
        }
        else
            cnt++;
    }
    cout << mx << '\n'
         << cnt;

    return 0;
}
