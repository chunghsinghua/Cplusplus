#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int d[N], p[N];

multiset<int> mset;

int _find(int a)
{
    if (p[a] < 0)
        return a;
    return p[a] = _find(p[a]);
}

void _union(int a, int b)
{
    int g1 = _find(a);
    auto it = mset.find(-p[g1]);
    mset.erase(it);
    int g2 = _find(b);
    it = mset.find(-p[g2]);
    mset.erase(it);
    p[g1] += p[g2];
    p[g2] = g1;
    mset.insert(-p[g1]);
}

int main()
{
    // freopen("P_3_10_5.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
        if (d[i])
        {
            p[i] = -1;
            mset.insert(1);
            if (d[i - 1])
                _union(i - 1, i);
        }
    }
    int mx = *mset.rbegin(), mn = *mset.begin();
    int t;
    for (int i = 0; i < k; ++i)
    {
        cin >> t;
        d[t] = 1;
        p[t] = -1;
        mset.insert(1);
        if (d[t - 1])
            _union(t - 1, t);
        if (d[t + 1])
            _union(t, t + 1);
        mx += *mset.rbegin();
        mn += *mset.begin();
    }
    cout << mx << "\n"
         << mn;
    return 0;
}
