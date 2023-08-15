#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

ll p = 1e9 + 9;
pair<ll, ll> fun(ll x, ll y, int n)
{
    if (n == 1)
        return {x, y};
    if (n & 1)
    {
        pair<ll, ll> t = fun(x, y, n - 1);
        ll a = t.first, b = t.second;
        return {(a * x + 2 * b * y) % p, (b * x + a * y) % p};
    }
    pair<ll, ll> t = fun(x, y, n / 2);
    ll a = t.first, b = t.second;
    return {(a * a + 2 * b * b) % p, 2 * a * b % p};
}
int main()
{
    freopen("Q_2_13_5.in", "r", stdin);
    ll x, y, b;
    cin >> x >> y >> b;
    pair<ll, ll> t = fun(x, y, b);
    cout << t.first << ' ' << t.second;
    return 0;
}
