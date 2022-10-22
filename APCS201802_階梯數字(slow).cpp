#include <bits/stdc++.h>

using namespace std;

#define N 1000000
typedef long long ll;

int fun(ll n)
{
    ll d = 9;
    while (n)
    {
        int t = n % 10;
        if (t > d)
            return 0;
        d = t;
        n /= 10;
    }
    return 1;
}

int main()
{
    freopen("P_6_19_3.in", "r", stdin);
    ll n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += fun(i);
    cout << ans;
    return 0;
}
