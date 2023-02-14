#include <bits/stdc++.h>

using namespace std;

#define N 200005
typedef long long ll;

int w[N], n, m, p, s, t;
pair<int, int> ptr[N];

int dfs(int root)
{
    if (root >= n)
        return w[root];
    return w[root] = dfs(ptr[root].first) + dfs(ptr[root].second);
}

int main()
{
    freopen("P_8_5_2.in", "r", stdin);
    cin >> n >> m;
    for (int i = n; i < 2 * n; ++i)
        cin >> w[i];
    int in[110];
    for (int i = 0; i < m; ++i)
        cin >> in[i];
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> p >> s >> t;
        ptr[p].first = s, ptr[p].second = t;
    }
    dfs(1);
    for (int i = 0; i < m; ++i)
    {
        int v = 1;
        while (v < n)
        {
            if (w[ptr[v].first] <= w[ptr[v].second])
                v = ptr[v].first;
            else
                v = ptr[v].second;
            w[v] += in[i];
        }
        if (i > 0)
            cout << ' ';
        cout << v;
    }
    return 0;
}
