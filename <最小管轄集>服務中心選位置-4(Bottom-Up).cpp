#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    freopen("Q_8_9_5.in", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1), tree(n + 1);
    vector<bool> visit(n + 1, false);
    vector<int> p(n + 1), deg(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> que;
    que.push(1);
    while (!que.empty())
    {
        int v = que.front();
        visit[v] = true;
        que.pop();
        for (int e : adj[v])
        {
            if (visit[e])
                continue;
            tree[v].push_back(e);
            que.push(e);
            deg[v]++;
            p[e] = v;
        }
    }
    queue<int> que2;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 0)
            que2.push(i);
    int cnt = 0;
    vector<int> flag(n + 1);
    while (!que2.empty())
    {
        int v = que2.front();
        if (v == 1)
            break;
        int parent = p[v];
        que2.pop();
        if (flag[v] == 0)
        {
            flag[parent] = 1;
        }
        else if (flag[v] == 1)
        {
            cnt++;
            if (flag[parent] != 1)
                flag[parent] = 2;
        }
        if (--deg[parent] == 0)
            que2.push(parent);
    }
    if (flag[1] == 1 || flag[1] == 0)
        cnt++;
    cout << cnt;
    return 0;
}
