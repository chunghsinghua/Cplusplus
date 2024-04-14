#include <bits/stdc++.h>
using namespace std;

#define N 1010
typedef long long ll;

map<char, int> cmap = {{'A', 0}, {'U', 1}, {'C', 2}, {'G', 3}, {'@', 4}};

int main()
{
    // freopen("P_4_9_2.in", "r", stdin);
    int n, m, i, j;
    cin >> n >> m;
    string s;
    vector<int> p(n + 1), deg(n + 1);
    vector<vector<int>> rna(n + 1, vector<int>(m, 0));
    for (int k = 0; k < n; ++k)
    {
        cin >> i >> j >> s;
        if (i != j)
        {
            p[i] = j;
            deg[j]++;
        }
        for (int k = 0; k < m; ++k)
            rna[i][k] = cmap[s[k]];
    }
    vector<int> que;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 0)
            que.push_back(i);
    int head = 0;
    while (head < que.size())
    {
        int v = que[head++];
        int parent = p[v];
        if (parent == 0)
            break;
        if (--deg[parent] == 0)
            que.push_back(parent);
    }
    int tot = 0;
    for (int i = 0; i < m; ++i)
    {
        vector<vector<int>> cost(n + 1, vector<int>(4, 0));
        for (int e : que)
        {
            int ch = rna[e][i];
            if (ch < 4)
            {
                tot += cost[e][ch];
                for (int j = 0; j < 4; ++j)
                    if (ch != j)
                        cost[p[e]][j]++;
            }
            else
            {
                int mcost = 1e9;
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
