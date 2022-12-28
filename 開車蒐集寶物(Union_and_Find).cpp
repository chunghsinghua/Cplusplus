#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

vector<int> adj[N];
int w[N], g[N];

int ffind(int x)
{
    if (g[x] < 0)
        return x;
    return g[x] = ffind(g[x]);
}

void funion(int x, int y)
{
    if (g[x] <= g[y])
    {
        g[x] += g[y];
        g[y] = x;
        w[x] += w[y];
    }
    else
    {
        g[y] += g[x];
        g[x] = y;
        w[y] += w[x];
    }
}

int main()
{
    freopen("P_7_2_3.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    memset(g, -1, sizeof(g));

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        int g1 = ffind(a);
        int g2 = ffind(b);
        if (g1 != g2)
            funion(g1, g2);
    }

    int mx = 0;
    for (int i = 0; i < n; ++i)
        if (g[i] < 0)
            mx = max(w[i], mx);

    cout << mx;

    return 0;
}
