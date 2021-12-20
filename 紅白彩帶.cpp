#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int c[N], p[N];
multiset<int> mset;

int _find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = _find(p[x]);
}
void _union(int x, int y)
{
    int g1 = _find(x);
    int g2 = _find(y);
    if (-p[g1] < -p[g2])
        swap(g1, g2);
    auto it = mset.find(-p[g1]);
    mset.erase(it);
    it = mset.find(-p[g2]);
    mset.erase(it);
    if (g1 != g2)
    {
        p[g1] += p[g2];
        p[g2] = g1;
    }
    mset.insert(-p[g1]);
}

int main()
{
    freopen("Q_7_11_1.in", "r", stdin);
    memset(p, -1, sizeof(p));
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
                _union(i - 1, i);
        }
    }
    int mx = *mset.rbegin();
    int mn = *mset.begin();
    for (int i = 0; i < k; ++i)
    {
        int idx;
        cin >> idx;
        c[idx] = 1;
        p[idx] = -1;
        mset.insert(1);
        if (c[idx - 1])
            _union(idx - 1, idx);
        if (c[idx + 1])
            _union(idx, idx + 1);
        mx += *mset.rbegin();
        mn += *mset.begin();
    }
    cout << mx << "\n"
         << mn << "\n";
    return 0;
}
