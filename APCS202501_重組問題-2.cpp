#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

multiset<int> mnvec({1000}), mxvec({0});
int last;

void fun(multiset<int> p, vector<int> d, int v)
{
    for (auto e : p)
    {
        auto it = lower_bound(d.begin(), d.end(), abs(v - e));
        if (it == d.end() || *it != abs(v - e))
            return;
        d.erase(it);
    }
    p.insert(v);
    if (d.empty())
    {
        if (p < mnvec)
            mnvec = p;
        if (p > mxvec)
            mxvec = p;
        return;
    }
    v = d.back();
    fun(p, d, v);
    fun(p, d, last - v);
}

int main()
{
    // freopen("P_5_4_1.in", "r", stdin);
    int n, m;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl
             << 0;
        return 0;
    }
    m = n * (n - 1) / 2;
    vector<int> d(m, 0);
    for (int i = 0; i < m; ++i)
        cin >> d[i];
    multiset<int> point({0});
    sort(d.begin(), d.end());
    last = d.back();
    fun(point, d, last);
    for (int e : mnvec)
        cout << e << ' ';
    cout << endl;
    for (int e : mxvec)
        cout << e << ' ';

    return 0;
}
