#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_7_11_5.in", "2r", stdin);
    int n, m, mod;
    cin >> n >> m >> mod;
    vector<pair<ll, ll>> seg(n); // right, left
    for (int i = 0; i < n; ++i)
        cin >> seg[i].second;
    for (int i = 0; i < n; ++i)
        cin >> seg[i].first;
    sort(seg.begin(), seg.end());
    map<int, ll> dp; // point, prefixsum
    dp.insert({0, 1});
    for (auto e : seg)
    {
        if (e.first != dp.rbegin()->first)
            dp.insert({e.first, dp.rbegin()->second});
        if (e.second == 0)
            dp.rbegin()->second = (dp.rbegin()->second + prev(dp.rbegin())->second) % mod;
        else
            dp.rbegin()->second = (dp.rbegin()->second + prev(dp.rbegin())->second - prev(dp.lower_bound(e.second))->second + mod) % mod;
    }
    if (dp.rbegin()->first != m)
        cout << 0;
    else
        cout << (dp.rbegin()->second - prev(dp.rbegin())->second + mod) % mod;
    return 0;
}
