#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int t[N], deg[N], mark[N];

int main()
{
    freopen("Q_8_10_3.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> t[i];
        deg[t[i]]++;
    }
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
            mark[t[v]] = 1;
            total++;
        }

        if (--deg[t[v]] == 0)
            que.push(t[v]);
    }
    if (!mark[0])
        total++;
    cout << n - total;
    return 0;
}
