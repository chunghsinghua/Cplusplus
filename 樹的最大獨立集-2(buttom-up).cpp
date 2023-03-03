#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;
int p[N], deg[N], mark[N];

int main()
{
    freopen("P_8_8_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> p[i];
        deg[p[i]]++;
    }
    p[0] = -1;
    queue<int> que;
    for (int i = 0; i < n; ++i)
        if (deg[i] == 0)
            que.push(i);
    int total = 0;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        if (v == 0)
            break;
        if (!mark[v])
        {
            total++;
            mark[p[v]] = 1;
        }
        if (--deg[p[v]] == 0)
            que.push(p[v]);
    }
    if (!mark[0])
        total++;
    cout << total;
    return 0;
}
