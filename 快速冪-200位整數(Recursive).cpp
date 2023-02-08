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
    freopen("Q_2_4_3.in", "r", stdin);
    string s;
    cin >> s;
    ll y, p;
    cin >> y >> p;
    ll ret = 0;
    for (auto e : s)
        ret = (ret * 10 + e - '0') % p;
    cout << fun(ret, y, p);
    return 0;
}
