#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int c[N], p[N];
multiset<int> mset;

int ffind(int x)
{
    if (p[x] >= 0)
        x = ffind(p[x]);
    return x;
}

void funion(int x, int y)
{
    int g1 = ffind(x);
    int g2 = ffind(y);
    auto it = mset.find(-p[g1]);
    mset.erase(it);
    it = mset.find(-p[g2]);
    mset.erase(it);
    p[g1] += p[g2];
    p[g2] = g1;
    mset.insert(-p[g1]);
}

int main()
{
    freopen("Q_7_11_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        if (c[i])
        {
            p[i] = -1;
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
        p[pos] = -1;
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
