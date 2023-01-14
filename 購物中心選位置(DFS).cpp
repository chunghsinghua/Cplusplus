#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

vector<pair<int, int>> adj[N];
int num[N], median = -1, total, n;

void dfs(int root)
{
    for (auto e : adj[root])
    {
        int to = e.first, wei = e.second;
        dfs(to);
        num[root] += num[to];
        total += min(num[to], n - num[to]) * wei;
    }
    num[root]++;
    if (median < 0 && num[root] >= n / 2)
        median = root;
}

int main()
{
    freopen("P_8_3_4.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        int p, wei;
        cin >> p >> wei;
        adj[p].push_back({i, wei});
    }

    dfs(0);
    cout << median << '\n'
         << total;

    return 0;
}
