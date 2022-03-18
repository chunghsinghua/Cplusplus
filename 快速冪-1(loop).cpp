#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

pair<int, int> d[N];

int main()
{
    freopen("p_2_3_1.in", "r", stdin);
    ll x, y, p;
    cin >> x >> y >> p;
    ll ans = 1;
    while (y)
    {
        if (y % 2)
            ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }

    cout << ans;

    return 0;
}
