#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;
int deg[N], mark[N], p[N];

vector<int> adj[N], tree[N];

void conv(int v, int parent)
{
    for (int e : adj[v])
    {
        if (e != parent)
        {
            tree[v].push_back(e);
            deg[v]++;
            p[e] = v;
            conv(e, v);
        }
    }
}

int main()
{
    freopen("Q_8_9_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    conv(1, -1);
    queue<int> que;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 0)
            que.push(i);
    int total = 0;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        if (v == 1)
            break;
        if (mark[v] == 0) // not be dominated;
        {
            mark[p[v]] = 1; // dominate
        }
        if (mark[v] == 1)
        {
            total++;
            if (mark[p[v]] != 1)
                mark[p[v]] = 2;
        } // be dominated, but not dominate any
        if (--deg[p[v]] == 0)
            que.push(p[v]);
    }
    if (mark[1] == 1 || mark[1] == 0)
        total++;
    cout << total;
    return 0;
}
