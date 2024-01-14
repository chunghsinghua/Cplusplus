#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int main()
{
    // freopen("Q_7_11_5.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p, q, r, m, n, u, v;
    cin >> p >> q >> r >> m;
    n = p + q + r;
    vector<int> data(n + 1);
    for (int i = 1; i <= p; ++i)
        cin >> data[i];
    vector<int> gate(n + 1);
    for (int i = p + 1; i <= p + q; ++i)
        cin >> gate[i];
    vector<vector<int>> pred(n + 1), succ(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        succ[u].push_back(v);
        pred[v].push_back(u);
        indeg[v]++;
    }
    vector<int> dag, delay(n + 1, 0);
    for (int i = 1; i <= p; ++i)
        dag.push_back(i);
    int head = 0;
    while (head < dag.size())
    {
        v = dag[head++];
        for (int to : succ[v])
        {
            if (--indeg[to] == 0)
                dag.push_back(to);
        }
    }
    assert(dag.size() == n);
    for (int i = p; i < n; ++i)
    {
        v = dag[i];
        if (gate[v] == 1)
        {
            data[v] = data[pred[v][0]] & data[pred[v][1]];
            delay[v] = max(delay[pred[v][0]], delay[pred[v][1]]) + 1;
        }
        else if (gate[v] == 2)
        {
            data[v] = data[pred[v][0]] | data[pred[v][1]];
            delay[v] = max(delay[pred[v][0]], delay[pred[v][1]]) + 1;
        }
        else if (gate[v] == 3)
        {
            data[v] = data[pred[v][0]] ^ data[pred[v][1]];
            delay[v] = max(delay[pred[v][0]], delay[pred[v][1]]) + 1;
        }
        else if (gate[v] == 4)
        {
            data[v] = 1 - data[pred[v][0]];
            delay[v] = delay[pred[v][0]] + 1;
        }
        else
        {
            data[v] = data[pred[v][0]];
            delay[v] = delay[pred[v][0]];
        }
    }
    int mxdelay = 0;
    for (int i = p + q + 1; i <= n; ++i)
        mxdelay = max(mxdelay, delay[i]);
    cout << mxdelay << '\n';
    for (int i = p + q + 1; i <= n; ++i)
        cout << data[i] << ' ';
    return 0;
}
