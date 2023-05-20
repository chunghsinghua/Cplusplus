#include <bits/stdc++.h>

using namespace std;

#define N 200010
typedef long long ll;

int h[N], p[N];

int main()
{
    freopen("Q_3_5_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    h[0] = 2e7 + 1;
    ll ans = 0;
    multiset<pair<int, int>> mset;
    mset.insert({h[0], 0});
    for (int i = 1; i <= n; ++i)
    {
        auto it = mset.upper_bound({h[i] + p[i], n + 1});
        if (it != mset.end())
            ans += i - it->second - 1;

        it = mset.begin();
        while (it != mset.end() && it->first <= h[i])
            it = mset.erase(it);
        mset.insert({h[i], i});
    }
    cout << ans;
    return 0;
}
