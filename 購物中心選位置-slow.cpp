#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int num[N], parent[N], dis[N];
bool flag[N];
vector<pair<int, int>> adj[N];

void dfs(int n, int root)
{
    for (auto e : adj[n])
    {
        if (e.first != root)
        {
            dis[e.first] = dis[n] + e.second;
            dfs(e.first, n);
        }
    }
}

int main()
{
    freopen("P_8_3_4.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        int from, w;
        cin >> from >> w;
        adj[i].push_back({from, w});
        adj[from].push_back({i, w});
        parent[i] = from;
    }
    parent[0] = -1;
    for (int i = 0; i < n; ++i)
    {
        int v = i;
        while (v >= 0)
        {
            num[v]++;
            v = parent[v];
        }
    }

    for (int i = 0; i < n; ++i)
        if (num[i] >= n / 2)
            flag[parent[i]] = true;

    int median = 0;
    for (; median < n; ++median)
        if (!flag[median] && num[median] >= n / 2)
            break;

    cout << median << '\n';
    dfs(median, -1);
    int total = 0;
    for (int i = 0; i < n; ++i)
        total += dis[i];
    cout << total;
    return 0;
}
