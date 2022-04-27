#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int d[N];

void rec(vector<ll> &v, int i, ll prod, map<ll, ll> &mp, ll p)
{
    if (i >= v.size())
    {
        mp[prod] += 1;
        return;
    }
    rec(v, i + 1, prod * v[i] % p, mp, p);
    rec(v, i + 1, prod, mp, p);
    return;
}

ll fun(ll x, ll y, ll p)
{
    if (y == 0)
        return 1;
    if (y & 1)
        return x * fun(x, y - 1, p) % p;
    ll t = fun(x, y / 2, p);
    return t * t % p;
}

int main()
{
    freopen("P_2_9_5.in", "r", stdin);
    ll n, p, t;
    cin >> n >> p;
    vector<ll> v1, v2;
    for (int i = 0; i < n / 2; ++i)
    {
        cin >> t;
        v1.push_back(t);
    }
    for (int i = n / 2; i < n; ++i)
    {
        cin >> t;
        v2.push_back(t);
    }
    map<ll, ll> m1, m2;
    rec(v1, 0, 1, m1, p), rec(v2, 0, 1, m2, p);
    m1[1] -= 1, m2[1] -= 1;
    ll ans = (m1[1] + m2[1]) % p;
    for (auto e : m1)
    {
        ll x = e.first, num = e.second;
        ll y = fun(x, p - 2, p);
        auto it = m2.find(y);
        if (it != m2.end())
            ans = (ans + num * it->second) % p;
    }
    cout << ans;

    return 0;
}
