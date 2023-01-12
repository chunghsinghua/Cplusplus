#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int num[N], parent[N], dis[N], deg[N];
vector<pair<int, int>> adj[N];

void dfs(int n, int p)
{
    for (auto e : adj[n])
    {
        int to = e.first, w = e.second;
        if (to != p)
        {
            dis[to] = dis[n] + w;
            dfs(to, n);
        }
    }
}

int main()
{
    freopen("P_8_3_4.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        int p, w;
        cin >> p >> w;
        parent[i] = p;
        adj[p].push_back({i, w});
        adj[i].push_back({p, w});
        deg[p]++;
    }
    parent[0] = -1;
    queue<int> que;
    for (int i = 0; i < n; ++i)
        if (deg[i] == 0)
            que.push(i);

    int median = -1;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        num[v]++;
        if (median < 0 && num[v] >= n / 2)
            median = v;
        int p = parent[v];
        if (p == -1)
            break;

        num[p] += num[v];
        if (--deg[p] == 0)
            que.push(p);
    }

    cout << median << '\n';
    dfs(median, -1);
    int total = 0;
    for (int i = 0; i < n; ++i)
        total += dis[i];

    cout << total;

    return 0;
}
