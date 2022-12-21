#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

multiset<int> mset;
int g[N], c[N];

int ffind(int x)
{
    while (g[x] >= 0)
        x = g[x];
    return x;
}

void funion(int x, int y)
{
    int g1 = ffind(x);
    int g2 = ffind(y);
    auto it = mset.find(-g[g1]);
    mset.erase(it);
    it = mset.find(-g[g2]);
    mset.erase(it);
    if (g1 != g2)
    {
        g[g1] += g[g2];
        g[g2] = g1;
    }
    mset.insert(-g[g1]);
}

int main()
{
    freopen("Q_7_11_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    ;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        if (c[i])
        {
            g[i] = -1;
            mset.insert(1);
            if (c[i - 1])
                funion(i - 1, i);
        }
    }

    int mn = *mset.begin();
    int mx = *mset.rbegin();
    while (k--)
    {
        int pos;
        cin >> pos;
        c[pos] = 1;
        g[pos] = -1;
        mset.insert(1);
        if (c[pos - 1])
            funion(pos - 1, pos);
        if (c[pos + 1])
            funion(pos + 1, pos);
        mn += *mset.begin();
        mx += *mset.rbegin();
    }
    cout << mx << '\n'
         << mn;
    return 0;
}
