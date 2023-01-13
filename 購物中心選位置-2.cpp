#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int num[N], parent[N], dis[N], deg[N], wei[N];
vector<pair<int, int>> adj[N];

int main()
{
    freopen("P_8_3_2.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> parent[i] >> wei[i];
        deg[parent[i]]++;
    }
    parent[0] = -1;
    queue<int> que;
    for (int i = 0; i < n; ++i)
        if (deg[i] == 0)
            que.push(i);

    int median = -1, total = 0;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        num[v]++;
        total += wei[v] * min(num[v], n - num[v]);
        if (median < 0 && num[v] >= n / 2)
            median = v;
        int p = parent[v];
        if (p == -1)
            break;

        num[p] += num[v];
        if (--deg[p] == 0)
            que.push(p);
    }

    cout << median << '\n'
         << total;

    return 0;
}
