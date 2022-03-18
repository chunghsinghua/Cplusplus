#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

pair<int, int> d[N];

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
    freopen("p_2_3_5.in", "r", stdin);
    ll x, y, p;
    cin >> x >> y >> p;

    cout << fun(x, y, p);

    return 0;
}
