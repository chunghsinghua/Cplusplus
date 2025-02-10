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
    vector<ll> p({0}), dp({1});
    for (auto e : seg)
    {
        if (e.first != p.back())
        {
            p.push_back(e.first);
            dp.push_back(dp.back());
        }
        if (e.second == 0)
            dp.back() = (dp.back() + dp[dp.size() - 2]) % mod;
        else
        {
            int idx = distance(p.begin(), lower_bound(p.begin(), p.end(), e.second)) - 1;
            dp.back() = (dp.back() + dp[dp.size() - 2] - dp[idx] + mod) % mod;
        }
    }
    if (p.back() != m)
        cout << 0;
    else
        cout << (dp.back() - dp[dp.size() - 2] + mod) % mod;
    return 0;
}
