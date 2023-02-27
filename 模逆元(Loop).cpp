#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

ll d[N];

ll exp(ll x, ll y, ll p)
{
    ll ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % p;
        y >>= 1;
        x = x * x % p;
    }
    return ret;
}

int main()
{
    freopen("Q_2_8_4.in", "r", stdin);
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    for (int i = 0; i < n; ++i)
    {
        cout << exp(d[i], p - 2, p) << " ";
    }
    return 0;
}
