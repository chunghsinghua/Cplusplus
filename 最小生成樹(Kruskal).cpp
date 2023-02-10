#include <bits/stdc++.h>

using namespace std;

#define N 10005
typedef long long ll;
#define oo 1000000001

struct EDGE
{
    int u, v, w;
};
bool cmp(EDGE &a, EDGE &b)
{
    return a.w < b.w;
}

int g[N];

int ffind(int n)
{
    if (g[n] < 0)
        return n;
    return g[n] = ffind(g[n]);
}

bool funion(int x, int y)
{
    int g1 = ffind(x);
    int g2 = ffind(y);
    if (g1 == g2)
        return false;
    if (g[g1] >= g[g2])
        swap(g1, g2);
    g[g1] += g[g2];
    g[g2] = g1;
    return true;
}

int main()
{
    freopen("P_7_12_2.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<EDGE> edge;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    sort(edge.begin(), edge.end(), cmp);
    memset(g, -1, sizeof(g));
    int nedge = 0, total = 0;
    for (auto e : edge)
    {
        if (funion(e.u, e.v))
        {
            nedge++;
            total += e.w;
        }
    }
    if (nedge != n - 1)
        cout << -1;
    else
        cout << total;
    return 0;
}
