#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int chosen[N], p[N];
vector<int> adj[N], tree[N];

void father(int v, int parent)
{
    for (int e : adj[v])
    {
        if (e != parent)
        {
            p[e] = v;
            tree[v].push_back(e);
            father(e, v);
        }
    }
}
int dfs(int n)
{
    int num = 0;
    for (int e : tree[n])
    {
        num += dfs(e);
    }
    if (chosen[n])
    {
        num += 1;
        chosen[p[n]] = 0;
    }
    return num;
}

int main()
{
    freopen("Q_8_9_1.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int s, t;
        cin >> s >> t;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }
    for (int i = 1; i <= n; ++i)
        chosen[i] = 1;
    p[1] = -1;
    father(1, -1);
    cout << n - dfs(1))
    return 0;
}
