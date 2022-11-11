#include <bits/stdc++.h>

using namespace std;

#define N 10010
typedef long long ll;
#define oo 1000000000

vector<pair<int, int>> adj[N];
int pmn[N], pmx[N];

int findmn(int goal)
{
    if (pmn[goal] < oo)
        return pmn[goal];
    for (auto e : adj[goal])
    {
        int x = findmn(e.first);
        if (x < oo)
            pmn[goal] = min(pmn[goal], x + e.second);
    }
    return pmn[goal];
}

int findmx(int goal)
{
    if (pmx[goal] > -oo)
        return pmx[goal];
    for (auto e : adj[goal])
    {
        int x = findmx(e.first);
        if (x > -oo)
            pmx[goal] = max(pmx[goal], x + e.second);
    }
    return pmx[goal];
}

int main()
{
    // freopen("P_7_6_5.in", "r", stdin);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i)
    {
        int from, to, w;
        cin >> from >> to >> w;
        adj[to].push_back({from, w});
    }

    for (int i = 0; i < n; ++i)
        pmn[i] = oo, pmx[i] = -oo;
    pmn[s] = pmx[s] = 0;

    pmn[t] = findmn(t);
    pmx[t] = findmx(t);
    if (pmn[t] >= oo)
        cout << "No path\nNo path";
    else
        cout << pmn[t] << '\n'
             << pmx[t] << '\n';

    return 0;
}
