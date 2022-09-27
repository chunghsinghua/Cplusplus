#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;
vector<int> adj[N], tour;

void dfs(int s, int t)
{
    tour.push_back(t);
    for (int e : adj[t])
    {
        if (e == s)
            continue;
        dfs(t, e);
        tour.push_back(t);
    }
}

int main()
{
    freopen("P_8_1_3.in", "r", stdin);
    int n, a, b, w, total = 0;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        total += w;
    }
    for (int i = 0; i < n; ++i)
        sort(adj[i].begin(), adj[i].end());

    dfs(-1, 0);
    cout << total * 2 << "\n";
    for (int e : tour)
        cout << e << " ";

    return 0;
}
