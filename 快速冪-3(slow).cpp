#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

pair<int, int> d[N];

int main()
{
    freopen("p_2_3_5.in", "r", stdin);
    ll x, y, p;
    cin >> x >> y >> p;
    ll ans = 1;
    for (int i = 0; i < y; ++i)
        ans = ans * x % p;

    cout << ans;

    return 0;
}
