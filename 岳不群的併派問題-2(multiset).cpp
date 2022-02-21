#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int d[N];

int main()
{
    freopen("P_4_7_5.in", "r", stdin);
    int n;
    cin >> n;
    multiset<ll> mset;
    ll temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        mset.insert(temp);
    }
    ll ans = 0;
    while (mset.size() > 1)
    {
        ll t = *mset.begin();
        mset.erase(mset.begin());
        t += *mset.begin();
        mset.erase(mset.begin());
        ans += t;
        mset.insert(t);
    }
    cout << *mset.begin() << "\n"
         << ans << "\n";
    return 0;
}
