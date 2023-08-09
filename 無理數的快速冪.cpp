#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

ll p = 1000000009;

pair<ll, ll> fun(ll x, ll y, ll n)
{
    if (n == 1)
        return {x, y};
    if (n & 1)
    {
        pair<ll, ll> t = fun(x, y, n - 1);
        ll x2 = t.first;
        ll y2 = t.second;
        return {(x2 * x + 2 * y2 * y) % p, (x2 * y + y2 * x) % p};
    }
    pair<ll, ll> t = fun(x, y, n / 2);
    ll x2 = t.first, y2 = t.second;
    return {(x2 * x2 + 2 * y2 * y2) % p, 2 * x2 * y2 % p};
}

int main()
{
    freopen("Q_2_13_5.in", "r", stdin);
    ll x, y, n;
    cin >> x >> y >> n;
    pair<ll, ll> ans = fun(x, y, n);
    cout << ans.first << ' ' << ans.second;

    return 0;
}
