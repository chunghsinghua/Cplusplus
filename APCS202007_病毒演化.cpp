#include <bits/stdc++.h>
using namespace std;

#define N 1005
typedef long long ll;

map<char, int> conv = {{'A', 0}, {'U', 1}, {'C', 2}, {'G', 3}, {'@', 4}};

int main()
{
    // freopen("Q_6_5_5.in", "r", stdin);
    int n, m, i, j;
    string s;
    cin >> n >> m;
    vector<vector<int>> rna(n + 1, vector<int>(m));
    vector<int> p(n + 1), deg(n + 1);
    for (int k = 0; k < n; ++k)
    {
        cin >> i >> j >> s;
        if (i != j)
            p[i] = j;
        deg[p[i]]++;
        for (int j = 0; j < m; ++j)
            rna[i][j] = conv[s[j]];
    }
    vector<int> dag;
    int head = 0;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 0)
            dag.push_back(i);
    while (dag.size() < n)
    {
        int v = dag[head++];
        int parent = p[v];
        if (parent == 0)
            break;
        if (--deg[parent] == 0)
            dag.push_back(parent);
    }
    int tot = 0;
    for (int i = 0; i < m; ++i)
    {
        int cost[n + 1][4] = {0};
        for (int e : dag)
        {
            int ch = rna[e][i];
            if (ch < 4)
            {
                tot += cost[e][ch];
                for (int j = 0; j < 4; ++j)
                {
                    if (ch != j)
                        cost[p[e]][j]++;
                }
            }
            else
            {
                int mcost = 9e5;
                for (int j = 0; j < 4; ++j)
                    mcost = min(mcost, cost[e][j]);
                tot += mcost;
                for (int j = 0; j < 4; ++j)
                    if (cost[e][j] != mcost)
                        cost[p[e]][j]++;
            }
        }
    }
    cout << tot;
    return 0;
}
