#include <bits/stdc++.h>

using namespace std;

#define N 10010
typedef long long ll;

int d[N];

int _find(int x)
{
    if (d[x] == x)
        return x;
    return d[x] = _find(d[x]);
}

void _union(int x, int y)
{
    int g1 = _find(x);
    int g2 = _find(y);
    if (g1 != g2)
        d[g2] = g1;
}

int main()
{
    // freopen("P_3_4_5.in", "r", stdin);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i <= n; ++i)
        d[i] = i;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        _union(a, b);
    }
    for (int i = 0; i < q; ++i)
    {
        int a, b;
        cin >> a >> b;

        if (_find(a) == _find(b))
            cout << ":)\n";
        else
            cout << ":(\n";
    }
    return 0;
}
