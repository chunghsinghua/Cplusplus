#include <bits/stdc++.h>
using namespace std;

#define N 100010
typedef long long ll;

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
    freopen("Q_2_8_4.in", "r", stdin);
    ll n, p;
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
    {
        ll t;
        cin >> t;
        cout << fun(t, p - 2, p) << '\n';
    }
    return 0;
}
