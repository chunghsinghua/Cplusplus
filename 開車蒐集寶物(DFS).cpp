#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int d[N];
bool visit[N];
vector<int> adj[N];

int dfs(int n)
{
    visit[n] = true;
    int ret = d[n];
    for (int e : adj[n])
    {
        if (!visit[e])
           ret += dfs(e);
    }
    return ret;
}

int main()
{
    freopen("P_7_2_5.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int from, to;
    for (int i = 0; i < m; ++i)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (!visit[i])
            ans = max(ans, dfs(i));

    cout << ans;

    return 0;
}
