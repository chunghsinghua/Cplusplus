#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

int deg[N], p[N], f1[N], f0[N];

int main()
{
    freopen("P_8_11_5.in", "r", stdin);
    int n;
    cin >> n >> f1[1];
    for (int i = 2; i <= n; ++i)
    {
        cin >> p[i] >> f1[i];
        deg[p[i]]++;
    }
    queue<int> que;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 0)
            que.push(i);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        if (v == 1)
            break;
        int parent = p[v];
        f0[parent] += max(f1[v], f0[v]);
        f1[parent] += f0[v];
        if (--deg[parent] == 0)
            que.push(parent);
    }
    cout << max(f1[1], f0[1]);
    return 0;
}
