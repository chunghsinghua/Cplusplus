#include <bits/stdc++.h>

using namespace std;

#define N 15
typedef long long ll;

vector<int> ret, visit(N, 0);
vector<int> adj[N];
bool circle = false;

void dfs(int v)
{
    if (visit[v] == 1)
    {
        circle = true;
        return;
    }
    if (visit[v] == 2)
        return;
    visit[v] = 1;
    for (int to : adj[v])
        dfs(to);
    visit[v] = 2;
    ret.push_back(v);
}

int main()
{
    // freopen("Q_7_11_5.in", "r", stdin);
    int n = 8, m = 10;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; ++i)
        if (!visit[i])
            dfs(i);
    for (auto it = ret.rbegin(); it != ret.rend(); ++it)
        cout << *it << ' ';
    return 0;
}
