#include <bits/stdc++.h>
using namespace std;

#define N 50010
typedef long long ll;

vector<int> tour, adj[N], child[N];

void root(int p, int v)
{
    for (int u : adj[v])
    {
        if (u != p)
        {
            child[v].push_back(u);
            root(v, u);
        }
    }
}

void tsp(int root)
{
    tour.push_back(root);
    for (int u : child[root])
    {
        tsp(u);
        tour.push_back(root);
    }
}

int main()
{
    freopen("P_8_1_2.in", "r", stdin);
    int n, a, b, w, total = 0;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        total += w;
    }
    root(-1, 0);
    for (int i = 0; i < n; ++i)
        sort(child[i].begin(), child[i].end());

    tsp(0);
    cout << total * 2 << '\n';
    for (int v : tour)
        cout << v << ' ';

    return 0;
}
