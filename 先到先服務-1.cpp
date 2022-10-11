#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N];

int main()
{
    freopen("Q_4_8_5.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    multiset<ll> mset;
    ll t;
    for (int i = 0; i < m; ++i)
    {
        cin >> t;
        mset.insert(t);
    }
    for (int i = m; i < n; ++i)
    {
        cin >> t;
        ll mn = *mset.begin();
        mn += t;
        mset.erase(mset.begin());
        mset.insert(mn);
    }
    cout << *mset.rbegin();

    return 0;
}
