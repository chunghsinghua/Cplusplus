#include <bits/stdc++.h>

using namespace std;

#define N 100010
typedef long long ll;

int main()
{
    freopen("Q_2_4_5.in", "r", stdin);
    string s;
    ll y, p;
    cin >> s >> y >> p;
    ll x = 0;
    for (auto a : s)
        x = (x * 10 + (a - '0')) % p;
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    cout << ans;
    return 0;
}
