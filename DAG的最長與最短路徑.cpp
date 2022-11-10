#include <bits/stdc++.h>

using namespace std;

#define N 10010
typedef long long ll;
#define oo 1000000000

vector<pair<int, int>> adj[N];
int pmn[N], pmx[N], indeg[N];

int main()
{
    // freopen("P_7_6_2.in", "r", stdin);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i)
    {
        int from, to, w;
        cin >> from >> to >> w;
        adj[from].push_back({to, w});
        indeg[to]++;
    }

    for (int i = 0; i < n; ++i)
        pmn[i] = oo, pmx[i] = -oo;
    pmn[s] = pmx[s] = 0;
    queue<int> que;
    for (int i = 0; i < n; ++i)
        if (indeg[i] == 0)
            que.push(i);

    int cnt = 0;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        cnt++;
        for (auto e : adj[v])
        {
            if (pmn[v] < oo)
            {
                pmn[e.first] = min(pmn[e.first], pmn[v] + e.second);
                pmx[e.first] = max(pmx[e.first], pmx[v] + e.second);
            }
            if (--indeg[e.first] == 0)
                que.push(e.first);
        }
    }

    if (cnt != n)
        cout << "Not a DAG/n";
    if (pmn[t] >= oo)
        cout << "No path\nNo path";
    else
        cout << pmn[t] << '\n'
             << pmx[t];
    return 0;
}
