#include <bits/stdc++.h>

using namespace std;

#define N 60010
typedef long long ll;

int data[N], lc[N], rc[N], gate[N], delay[N];

void dp(int v)
{
    if (data[v] >= 0)
        return;
    dp(lc[v]);
    if (gate[v] == 4)
    {
        data[v] = 1 - data[lc[v]];
        delay[v] = delay[lc[v]] + 1;
        return;
    }
    dp(rc[v]);
    if (gate[v] == 1)
        data[v] = data[lc[v]] & data[rc[v]];
    else if (gate[v] == 2)
        data[v] = data[lc[v]] | data[rc[v]];
    else if (gate[v] == 3)
        data[v] = data[lc[v]] ^ data[rc[v]];
    else
        ;
    delay[v] = max(delay[lc[v]], delay[rc[v]]) + 1;
    return;
}

int main()
{
    // freopen("Q_7_11_5.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p, q, r, m, n, u, v;
    cin >> p >> q >> r >> m;
    n = p + q + r;
    memset(data, -1, sizeof(data));
    for (int i = 1; i <= p; ++i)
        cin >> data[i];
    for (int i = p + 1; i <= p + q; ++i)
        cin >> gate[i];
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        if (lc[v] == 0)
            lc[v] = u;
        else
            rc[v] = u;
    }
    int mxdelay = 0;
    for (int i = p + q + 1; i <= n; ++i)
    {
        dp(lc[i]);
        data[i] = data[lc[i]];
        mxdelay = max(mxdelay, delay[lc[i]]);
    }
    cout << mxdelay << '\n';
    for (int i = p + q + 1; i <= n; ++i)
        cout << data[i] << ' ';
    return 0;
}
