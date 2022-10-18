#include <bits/stdc++.h>

using namespace std;

#define N 20
typedef long long ll;

vector<int> adj[N];
int indeg[N];

int main()
{
    // freopen("P_7_2_5.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        indeg[to]++;
    }
    vector<int> topo;
    int head = 0;
    for (int i = 0; i < n; ++i)
        if (indeg[i] == 0)
            topo.push_back(i);
    while (head < topo.size())
    {
        int v = topo[head++];
        for (int u : adj[v])
        {
            if (--indeg[u] == 0)
                topo.push_back(u);
        }
    }
    if (topo.size() < n)
        cout << "Not a dag.";
    else
    {
        for (int u : topo)
            cout << u << ' ';
        cout << '\n';
    }

    return 0;
}
