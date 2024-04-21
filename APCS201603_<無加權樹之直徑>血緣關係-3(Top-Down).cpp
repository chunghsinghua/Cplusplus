#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

vector<int> adj[N];
bool notroot[N];
int maxd = 0, h[N];

void dfs(int v)
{
    for (int e : adj[v])
    {
        dfs(e);
        maxd = max(maxd, h[e] + 1 + h[v]);
        h[v] = max(h[v], h[e] + 1);
    }
}

int main()
{
    freopen("P_8_14_4.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        notroot[b] = true;
    }
    int root = 0;
    while (notroot[root])
        root++;
    dfs(root);
    cout << maxd;
    return 0;
}
