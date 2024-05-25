#include <bits/stdc++.h>
using namespace std;

#define N 510
typedef long long ll;

void conv(vector<vector<int>> &adj, vector<vector<int>> &tree, int v, int n, vector<int> &deg, vector<int> &p)
{
    vector<bool> visit(n + 1);
    visit[v] = true;
    queue<int> que;
    que.push(v);
    while (!que.empty())
    {
        int vv = que.front();
        que.pop();
        for (int e : adj[vv])
        {
            if (!visit[e])
            {
                visit[e] = true;
                tree[vv].push_back(e);
                p[e] = vv;
                deg[vv]++;
                que.push(e);
            }
        }
    }
}

int main()
{
    freopen("Q_8_9_5.in", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1), tree(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> deg(n + 1), p(n + 1), flag(n + 1);
    conv(adj, tree, 1, n, deg, p);
    queue<int> que;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 0)
            que.push(i);
    int tot = 0;
    while (!que.empty())
    {
        int v = que.front();
        if (v == 1)
            break;
        que.pop();
        int parent = p[v];
        if (flag[v] == 0)
        {
            flag[parent] = 1;
        }
        else if (flag[v] == 1)
        {
            tot++;
            if (flag[parent] != 1)
                flag[parent] = 2;
        }
        if (--deg[parent] == 0)
            que.push(parent);
    }
    if (flag[1] == 1 || flag[1] == 0)
        tot++;
    cout << tot;
    return 0;
}
